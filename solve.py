import math
from sortedcontainers import SortedSet

n = int(input())
arr = list(map(int, input().split()))
s = SortedSet(arr)

ans = [0] * n

for i in range(n):
    cnt = len(s) - s.bisect_right(arr[i])
    ans[cnt] += 1

for a in ans:
    print(a)
