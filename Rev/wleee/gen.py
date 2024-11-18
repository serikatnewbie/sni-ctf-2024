flag = b"SNI{C#_dotnet_s1ngL3_f1l3_1s_S0ooo0_b!ggG}"

def enc(msg, shf, nbit):
    if type(msg) == str:
        msg = msg.encode()
        
    assert type(msg) == bytes, "msg must be bytes"
    
    res = [[] for _ in range(1 << nbit)]
    
    for i, c in enumerate(msg):
        res[(c >> shf) % (1 << nbit)].append(i)
    
    return res

print(enc(flag, 4, 3))
print(enc(flag, 1, 3))
print(enc(flag, 0, 1))