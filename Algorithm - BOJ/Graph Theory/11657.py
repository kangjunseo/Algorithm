import sys
input = sys.stdin.readline
INF = int(1e9)

N,M = map(int,input().split())
G = []
for _ in range(M): G.append(tuple(map(int,input().split())))
dist = [INF for _ in range(N+1)]

def bellmanford(start):    
    dist[start] = 0
    for i in range(N):
        for j in range(M):
            c,n,t = G[j]
            if dist[c]!=INF and dist[n]>dist[c]+t: 
                dist[n]=dist[c]+t
                if i==N-1: return True
    return False

if bellmanford(1): print(-1)
else:
    for i in range(2,N+1): print(-1) if dist[i]==INF else print(dist[i])
