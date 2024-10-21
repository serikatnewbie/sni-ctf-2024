import random
import os

FLAG = open("flag.txt", "rb").read()
FLAG = os.urandom(70-len(FLAG)) + FLAG
LEN = 40

def generate(mask):
    rand = [random.getrandbits(40) for _ in range(len(mask))]
    target = sum(map(lambda x, y: x * int(y), rand, mask))
    return rand, target

def bytes2bin(msg):
    return bin(int.from_bytes(msg,'big'))[2:]

def main():
    flag = bytes2bin(FLAG)
    assert len(flag) == 560
    flag_blocks = [list(flag[i:i+LEN]) for i in range(0,len(flag), LEN)]
    for block in flag_blocks:
        rand, target = generate(block)
        print([rand, target])   

if __name__ == "__main__":
    main()
