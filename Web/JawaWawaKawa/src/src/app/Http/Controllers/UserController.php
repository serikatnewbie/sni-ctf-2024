<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\User;
use Illuminate\Support\Facades\Cookie;

class UserController extends Controller
{
    public function login(Request $request){
        $user = User::where(["username" => $request->username])->first();
        if(!$user) return "user not found";
        $verify = password_verify($request->password, $user->password);
        if($verify) {
            $privateKeyPath = '../private_key.pem';
            $privateKey = file_get_contents($privateKeyPath);
            $header = json_encode(['alg' => 'RS256', 'typ' => 'JWT', "kid" => "bengsky123456789", "url"=>"http://localhost:8000/.well-known/jwks.json"]);
            $payload = json_encode([
                    'username' => $request->username
            ]);
            $base64UrlHeader = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($header));
            $base64UrlPayload = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($payload));
            $signatureInput = $base64UrlHeader . '.' . $base64UrlPayload;
            $signature = '';
            openssl_sign($signatureInput, $signature, $privateKey, OPENSSL_ALGO_SHA256);
            $base64UrlSignature = str_replace(['+', '/', '='], ['-', '_', ''], base64_encode($signature));
            $jwt = $base64UrlHeader . '.' . $base64UrlPayload . '.' . $base64UrlSignature;

            $cookie = cookie('token', $jwt, 600000000000);
            return response()->json(['token' => 'Cookie has been set!'])->cookie($cookie);
        }
        return "?";
    }
    public function register(Request $request){

        if(User::where(["username" => $request->username])->first()){
            return "Username already registered";
        }
        $isVerified = $request->ip() == "127.0.0.1" ? true : false;
        User::create([
            "username" => $request->username,
            "password" => $request->password,
            "verified" => $isVerified
        ]);
        return "Success";
    }
    public function get_flag(Request $request){
        $user = json_decode(base64_decode(explode(".", $request->header('authorization'))[1]))->username;
        try{
            $u = User::where(["username" => $user])->first();
            if($u) if($u->verified == 1)  return getenv("FLAG");
        }
        catch(\CatchException $e){

        }
        return "?";
    }
}
