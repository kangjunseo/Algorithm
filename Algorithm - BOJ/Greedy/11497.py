import sys
from collections import deque
input = sys.stdin.readline

T = int(input())
L = [None for _ in range(T)]
ans = [deque([]) for _ in range(T)]
dist = [[]for _ in range(T)]
for i in range(T):
    temp = int(input())
    L[i] = deque(sorted(map(int, input().split())))
    ans[i].append(L[i].pop())
    while L[i]: 
        ans[i].appendleft(L[i].pop())
        if not L[i]: break
        ans[i].append(L[i].pop())
    
    for j in range(temp): dist[i].append(abs(ans[i][j]-ans[i][j-1]))

for i in dist: print(max(i))
