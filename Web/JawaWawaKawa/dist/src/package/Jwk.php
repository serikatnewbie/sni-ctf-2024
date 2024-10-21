<?php

namespace Bengsky\Jwk;
use \Exception;
class Jwk
{
    
    private $token = null;
    public function __construct($token){
        $this->token = $token;
    }

    private function getKeys($url){
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_URL, $url);
        curl_setopt($ch, CURLOPT_TIMEOUT, 1);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        $result = curl_exec($ch);
        return json_decode($result);
    }
    public function verify(){
        try{
            $token = $this->token;
            [$header, $payload, $signature] = explode(".", $token);
            $headObj = json_decode(base64_decode($header));
            $url = $headObj->url;
            $kid = $headObj->kid;
            $whitelist = json_decode(file_get_contents('../public/.well-known/jwks.json'));
            $pass = false;
            foreach($whitelist as $w){
                if($w->kid == $kid) $pass = true;
            }
            if(!$pass) throw new Exception("KID Not whitelisted");
            foreach($this->getKeys($url) as $key){
                if($key->kid == $kid) $pubKey = $key;
            }
            $publicKey = openssl_pkey_get_public($this->createPublicKey($key));
            $isValid = openssl_verify($header.".".$payload, $this->base64url_decode($signature), $publicKey, OPENSSL_ALGO_SHA256);
            return $isValid;                
        }
        catch(\CatchException $e){
            echo $e;
            return false;
        }
        return true;
    }

    public function toJson()
    {
        return json_encode([
            'keys' => array_map(function ($keyId, $key) {
                return [
                    'kty' => 'oct', // Example: symmetric key type
                    'kid' => $keyId,
                    'k' => base64_encode($key),
                ];
            }, array_keys($this->keys), $this->keys)
        ]);
    }
    public function base64url_decode($data) {
        return base64_decode(strtr($data, '-_', '+/'));
    }
    public function createPublicKey($jwk) {
        $n = base64_decode($jwk->n);
        $e = base64_decode($jwk->e);
        return file_get_contents('../public_key.pem');
    }
    
    
}
