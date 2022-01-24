import sys
from collections import defaultdict, deque
input = sys.stdin.readline

V = int(input())
G = defaultdict(list)
for _ in range(V):
    temp = list(map(int,input().split()))
    idx = 1
    while temp[idx]!=-1:
        G[temp[0]].append((temp[idx],temp[idx+1]))
        idx+=2

def dfs(start = 1):
    queue = deque([start])
    dist = [0 for _ in range(V+1)]
    ans = start
    dist_max = 0

    while queue:
        cur = queue.popleft()
        for node, weight in G[cur]:
            if dist[node]==0 and node!=start:
                queue.append(node)
                dist[node]+=(dist[cur]+weight)
                if dist_max<dist[node]:
                    dist_max = dist[node]
                    ans = node
    return ans, dist_max

print(dfs(dfs()[0])[1])
