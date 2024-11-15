import string

charset = string.printable.encode()

def check_flag(flag):
    for c in flag:
        if c not in charset:
            return False
    return True

result = bytes.fromhex("8f6c54103d16682e98ca66d8b1bb67a0007d57e166d719f12fcd2ca1884454aa")
key = [
    0x23,
    0x42,
    0x12,
    0x3a,
    0xe3,
    0x40,
    0x12,
    0x34,
    0xd3,
    0x02,
    0x10,
    0x0a
]

# solving half first
result = bytearray(result)
last = result[-1]
for i in range(len(result) // 2):
    result[i] ^= last

# bruteforce missing bytes
flag = []
for i in range(0x100):
    temp = result.copy()
    
    for j in range(len(result) // 2, len(result)):
        temp[j] ^= i

    for j in range(len(result) - 1, -1, -1):
        temp[j] = (temp[j] - (0x35 * (j + 1))) % 0x100

    for j in range(len(result) - 1, -1, -1):
        if j > 0:
            temp[j] ^= temp[j - 1]
        temp[j] = (temp[j] * pow(0x79, -1, 0x100)) % 0x100
        temp[j] ^= key[j % len(key)]
    
    flag.append(bytes(temp))

for f in flag:
    if check_flag(f):
        print(f)