from hashlib import sha256
from itertools import combinations
from tqdm import tqdm

def bin2bytes(binary : str):
    if len(binary) % 8 != 0:
        binary = binary.zfill(len(binary) + 8 - len(binary) % 8)
    return int(binary, 2).to_bytes(len(binary) // 8, byteorder='big')

def subset_sums_with_indices(arr):
    subsets = []
    for r in range(len(arr) + 1):
        for comb in combinations(enumerate(arr), r):
            indices, values = zip(*comb) if comb else ([], [])
            subsets.append((sum(values), list(indices)))
    return subsets

def subset_sum(arr, target):
    n = len(arr)
    left_half = arr[:n//2]
    right_half = arr[n//2:]

    left_sums = subset_sums_with_indices(left_half)
    right_sums = subset_sums_with_indices(right_half)
    right_sums.sort(key=lambda x: x[0])

    for l_sum, l_indices in tqdm(left_sums):
        r_sum_needed = target - l_sum
        low, high = 0, len(right_sums) - 1
        while low <= high:
            mid = (low + high) // 2
            r_sum, r_indices = right_sums[mid]
            if r_sum + l_sum == target:
                r_indices = [i + len(left_half) for i in r_indices]
                return l_indices + r_indices
            elif r_sum < r_sum_needed:
                low = mid + 1
            else:
                high = mid - 1

    return [] 

arr = [453375566034, 601695892619, 137881860072, 974990074025, 246294902014, 921417413369, 698072237267, 896900733308, 872484783742, 1005270746506, 112302403861, 564504041836, 217244491352, 259088650526, 836017361074, 621153619156, 1012375019100, 162852342670, 910264608177, 596260694085, 1064796217145, 932791472708, 487402996177, 585427869751, 966311223545, 893455158370, 374905359887, 112015722153, 250971413730, 369366806080, 319683007072, 105523882550, 562353943816, 620146139157, 729526121382, 1033753428277, 336611017934, 412710795700, 479936580997, 36401269014]
target = 10853151574459
result = subset_sum(arr, target)
assert sum([arr[i] for i in result]) == target
temp = ""
for i in result:
    temp += str(arr[i])
    temp += " "
temp = temp.strip()

print("RESULT:", temp)
print("SNI{"+sha256(temp.encode()).hexdigest()+"}")