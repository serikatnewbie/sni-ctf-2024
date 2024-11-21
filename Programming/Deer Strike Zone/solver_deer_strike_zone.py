from sortedcontainers import SortedDict

MOD_VAL = pow(16, 32)

def read_data(filename):
    f = open(filename, "r").read().strip().split("\n")
    n, m = f.pop(0).split(" ")
    query = []

    for x in f:
        temp = x.split(" ")
        query.append((int(temp[0]), int(temp[1])))
    
    return int(n), int(m), query

def derangement(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 0

    for i in range(2, n + 1):
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD_VAL
        if i % pow(10,6) == 0:
            print(i)

    return dp

def line_sweep(query):
    cage = SortedDict()

    for l, r in query:
        if l in cage:
            cage[l] += points[r-l+1]
        else:
            cage[l] = points[r-l+1]
        
        if (r+1) in cage:
            cage[r+1] -= points[r-l+1]
        else:
            cage[r+1] = -1*points[r-l+1]

    max_damage = 0
    damage = 0
    for x in list(cage.values()):
        damage += x
        max_damage = max(max_damage, damage)
    
    return max_damage

N, M, QUERY = read_data("testcase.in")
points = derangement(min(pow(10,7), N))
res = line_sweep(QUERY)

print("RESULT:", res)
print("SNI{"+hex(res)[2:]+"}")