from collections import deque

X = [-1,0,1,0]
Y = [0,1,0,-1]

N = int(input())
L = []
ans = []
visited = [[0 for _ in range(N)] for _ in range(N)]

def IsRange(a,b):
    if a>=0 and b>=0 and a<N and b<N: return True
    return False

def bfs(a,b):
    cnt = 1
    visited[a][b]=1
    queue = deque([(a,b)])
    while(queue):
        a,b = queue.popleft()
        for x,y in zip(X,Y):
            if(IsRange(a+x,b+y) and visited[a+x][b+y]==0):
                if L[a+x][b+y] == '1' :
                    queue.append((a+x,b+y))
                    cnt += 1
                    visited[a+x][b+y]=1
    return cnt

for _ in range(N): L.append(list(input()))
for i in range(N):
    for j in range(N):
        if(L[i][j]=='0'): visited[i][j]=1
        elif(L[i][j]=='1' and visited[i][j]==0): ans.append(bfs(i,j))

print(len(ans))
for i in sorted(ans): print(i)
