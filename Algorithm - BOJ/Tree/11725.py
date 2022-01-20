import sys
from collections import deque, defaultdict
input = sys.stdin.readline

N = int(input())
G = defaultdict(list)
for _ in range(N-1): 
    v,w = map(int, input().split())
    G[v].append(w)
    G[w].append(v)

level = [0 for _ in range(N+1)]
queue = deque([1])
while queue: 
    x = queue.popleft()
    for i in G[x]: 
        if level[i]==0 and i!=1:
            queue.append(i)
            level[i] = level[x]+1

for i in range(2,N+1): 
    for j in G[i]:
        if level[i]-level[j]==1: print(j)
