import sys
input = sys.stdin.readline
INF = int(1e9)

TC = int(input())

def bellmanford(start,G,dist,N,M):    
    dist[start] = 0
    for i in range(N):
        for j in range(M):
            c,n,t = G[j]
            if dist[n]>dist[c]+t: 
                dist[n]=dist[c]+t
                if i==N-1: return True
    return False


for _ in range(TC):
    N,M,W = map(int,input().split())
    G = []
    for _ in range(M): 
        S,E,T = map(int,input().split())
        G.append((S,E,T))
        G.append((E,S,T))
    for _ in range(W): 
        S,E,T = map(int,input().split())
        G.append((S,E,-T))
    dist = [INF for _ in range(N+1)]

    print('YES') if bellmanford(1,G,dist,N,2*M+W) else print('NO')
