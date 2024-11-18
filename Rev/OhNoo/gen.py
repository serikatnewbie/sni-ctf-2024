import os


def tohex(inst):
    return ", ".join([hex(x) for x in inst])

inst = "48 85 F6 74 7B 53 49 89 F2 49 89 C9 49 89 D3 41 B8 35 00 00 00 31 C9 31 F6 BB 79 00 00 00 66 90 48 89 C8 31 D2 49 F7 F1 41 0F B6 04 13 32 04 0F 48 83 C1 01 0F AF C3 31 C6 42 8D 04 06 41 83 C0 35 88 44 0F FF 4C 39 D1 75 D6 4C 89 D1 4C 89 D0 48 D1 E9 48 29 C8 0F B6 14 07 4C 89 D0 0F 1F 00 48 39 C8 73 06 42 0F B6 54 17 FF 30 14 07 48 83 E8 01 75 EC 32 17 5B 88 17 C3 66 0F 1F 44 00 00 31 D2 88 17 C3"
inst = bytes.fromhex(inst.replace(" ", ""))
n_inst = len(inst)

# ".byte 0x48, 0xb8, 0x33\n" // mov rax,<8byte>
# ".byte 0x48, 0xff, 0xc0\n" // inc rax
# ".byte 0xeb, 0x04\n" // jmp +6
# ".byte 0xff, 0xff\n" 
# ".byte 0x48, 0xb8\n" // mov rax,<8byte>
# ".byte 0xc6, 0x04, 0x2, 0x55\n" // mov byte ptr [rdx+rax], 0
# ".byte 0xeb, 0x05\n" // jmp +6
template = """".byte 0x48, 0xb8, {}\\n" // mov rax,<8byte>
".byte 0x48, 0xff, 0xc0\\n" // inc rax
".byte 0xeb, 0x04\\n" // jmp +6
".byte {}, {}\\n" 
".byte 0x48, 0xb8\\n" // mov rax,<8byte>
".byte 0xc6, 0x04, 0x2, {}\\n" // mov byte ptr [rdx+rax], ...
".byte 0xeb, 0x05\\n" // jmp +7
".byte {}, {}\\n" 

"""

res = ""
for x in inst[1:]:
    r = [_ for _ in os.urandom(5)]
    res += template.format(
        hex(r.pop()),
        hex(r.pop()),
        hex(r.pop()),
        hex(x),
        hex(r.pop()),
        hex(r.pop())
    )

print(res)
r = [hex(x) for x in os.urandom(n_inst)]
print(", ".join(r))