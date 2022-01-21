import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

N,M,X = map(int,input().split())
G = [[] for _ in range(N+1)]
rG = [[] for _ in range(N+1)]

for _ in range(M):
    s,e,t = map(int,input().split()) 
    G[s].append((e,t))
    rG[e].append((s,t))

dist = [INF for _ in range(N+1)]
rdist = [INF for _ in range(N+1)]

def dijkstra(start, G, dist):
    pq = []
    heapq.heappush(pq,(0,start))
    dist[start] = 0

    while pq:
        cost, cur = heapq.heappop(pq)
        if dist[cur] < cost: continue

        for i in G[cur]:
            target = cost + i[1]
            if target < dist[i[0]]:
                dist[i[0]] = target
                heapq.heappush(pq, (dist[i[0]],i[0]))

dijkstra(X,G,dist)
dijkstra(X,rG,rdist)

ans = 0
for i,j in zip(dist[1:],rdist[1:]): ans = max(ans,i+j)
print(ans)
