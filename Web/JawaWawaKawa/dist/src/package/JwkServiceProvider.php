<?php

namespace Bengsky\Jwk;

use Illuminate\Support\ServiceProvider;

class JwkServiceProvider extends ServiceProvider
{
    public function register()
    {
        $this->app->singleton(Jwk::class, function ($app) {
            return new Jwk();
        });
    }

    public function boot()
    {
        // Load routes, views, or any other bootstrapping needed
    }
}
