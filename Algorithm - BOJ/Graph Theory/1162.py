import sys
input = sys.stdin.readline
INF = int(1e19)

N,M,K = map(int,input().split())
G = [[] for _ in range(N+1)]

for _ in range(M):
    s,e,t = map(int,input().split()) 
    G[s].append((e,t))
    G[e].append((s,t))

dist = [[INF for _ in range(N+1)] for _ in range(K+1)]

def dijkstra(start):
    pq = []
    heapq.heappush(pq,(0,start,0))
    for i in range(K+1): dist[i][start]=0

    while pq:
        cost, cur, tuned = heapq.heappop(pq)
        if dist[tuned][cur] < cost: continue

        for i in G[cur]:
            target = cost + i[1]
            if target < dist[tuned][i[0]]:
                dist[tuned][i[0]] = target
                heapq.heappush(pq, (target,i[0],tuned))
            if tuned<K and cost < dist[tuned+1][i[0]]:
                dist[tuned+1][i[0]] = cost
                heapq.heappush(pq, (cost,i[0],tuned+1))

dijkstra(1)
ans = INF
for i in range(K+1): ans = min(ans,dist[i][N])
print(ans)
