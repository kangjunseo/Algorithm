import sys, heapq
input = sys.stdin.readline
INF = int(1e19)

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

T = int(input())

for _ in range(T):
    # input parsing
    n,m,t = map(int,input().split())
    s,g,h = map(int,input().split())
    G = [[] for _ in range(n+1)]
    goals = []
    for _ in range(m):
        a,b,d = map(int,input().split()) 
        G[a].append((b,d))
        G[b].append((a,d))
    for _ in range(t): goals.append(int(input()))
    dist = [INF for _ in range(n+1)]
    dist_g = [INF for _ in range(n+1)]
    dist_h = [INF for _ in range(n+1)]

    dijkstra(s,G,dist)
    dijkstra(g,G,dist_g)
    dijkstra(h,G,dist_h)

    for i in sorted(goals):
        if dist[i] == dist[g] + dist_g[h] + dist_h[i] or dist[i] == dist[h] + dist_g[h] + dist_g[i]: print(i,end=' ')
    print()
