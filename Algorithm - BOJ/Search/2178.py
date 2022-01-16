from collections import deque

X = [-1,0,1,0]
Y = [0,1,0,-1]
queue = deque([(0,0)])
N,M = map(int,input().split())
L = []
visited = [[0 for _ in range(M)] for _ in range(N)]

def IsRange(a,b):
    if a>=0 and b>=0 and a<N and b<M: return True
    return False

def bfs():
    visited[0][0]=1
    while(queue):
        a,b = queue.popleft()
        for x,y in zip(X,Y):
            if(IsRange(a+x,b+y) and visited[a+x][b+y]==0):
                if L[a+x][b+y] == '1' :
                    queue.append((a+x,b+y))
                    visited[a+x][b+y]=visited[a][b]+1
cnt = 0
for _ in range(N): L.append(list(input()))
bfs()
print(visited[N-1][M-1])
