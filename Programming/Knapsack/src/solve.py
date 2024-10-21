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

    for l_sum, l_indices in left_sums:
        r_sum_needed = target - l_sum
        low, high = 0, len(right_sums) - 1
        while low <= high:
            mid = (low + high) // 2
            r_sum, r_indices = right_sums[mid]
            if r_sum == r_sum_needed:
                r_indices = [i + len(left_half) for i in r_indices]
                return l_indices + r_indices
            elif r_sum < r_sum_needed:
                low = mid + 1
            else:
                high = mid - 1

    return [] 

def generate_arr(arr):
    return [1 if i in arr else 0 for i in range(40)]

r = open("output.txt", "r").readlines()
flag = []
for temp in tqdm(r):
    arr, target = eval(temp)
    result = subset_sum(arr, target)
    flag += generate_arr(result)

print(bin2bytes(''.join([str(i) for i in flag])))
