#!/usr/bin/env python3

# fmt:off
ct = [0, 24, 59, 86, 2, 14, 43, 17, 17, 24, 0, 54, 7, 46, 49, 11, 1, 11, 16, 10, 1, 0, 53, 58, 0, 0, 18, 18, 1, 53, 90, 57]
key = b"SerikatNewbieIndonesia"
# fmt:on

for i in range(len(ct)):
    ct[i] ^= key[i % len(key)]

v12 = len(ct)
v19 = 1
if v12 & 1 != 0:
    v4 = v12 - 2
else:
    v4 = v12 - 1

while v19 < v4:
    ct[v19], ct[v4] = ct[v4], ct[v19]
    v19 += 2
    v4 -= 2

print(bytes(ct).decode())
