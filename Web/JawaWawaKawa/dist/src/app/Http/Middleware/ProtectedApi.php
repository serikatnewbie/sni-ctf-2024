<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Symfony\Component\HttpFoundation\Response;
use Bengsky\Jwk\Jwk;
class ProtectedApi
{
    /**
     * Handle an incoming request.
     *
     * @param  \Closure(\Illuminate\Http\Request): (\Symfony\Component\HttpFoundation\Response)  $next
     */
    public function handle(Request $request, Closure $next): Response
    {
        try{
            $auth = $request->header('Authorization');
            if(!$auth) return abort(401);
        $token = explode(" ", $auth)[1];
        $jwk = new Jwk($token);
        if (!$jwk->verify()) return abort(401);
        }
        catch(\CatchException $e){
            return abort(401);
        }
        return $next($request);
    }
}
