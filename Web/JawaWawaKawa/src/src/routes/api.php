<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\UserController;

use App\Http\Middleware\ProtectedApi;
Route::post('/login', [UserController::class, 'login']);
Route::post('/register', [UserController::class, 'register']);


Route::get('/get_flag', [UserController::class, 'get_flag'])->middleware(ProtectedApi::class);
