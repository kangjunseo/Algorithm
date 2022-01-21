import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

V,E = map(int, input().split())
K = int(input())
G = [[] for _ in range(V+1)]
for _ in range(E): 
    u,v,w = map(int,input().split())
    G[u].append((v,w))
dist = [INF for _ in range(V+1)]
heap = []
heapq.heappush(heap,(0,K))
dist[K]=0

while heap:
    cost, current = heapq.heappop(heap)
    if dist[current] < cost: continue

    for i in G[current]:
        target = cost+ i[1]
        if target < dist[i[0]]:
            dist[i[0]]=target
            heapq.heappush(heap,(dist[i[0]],i[0]))

for i in dist[1:]: print('INF') if i==INF else print(i)
