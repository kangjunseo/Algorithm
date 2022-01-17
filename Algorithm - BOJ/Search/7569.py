import sys
from collections import deque

dx = [1,0,0,-1,0,0]
dy = [0,1,0,0,-1,0]
dz = [0,0,1,0,0,-1]

M,N,H = map(int,sys.stdin.readline().split())

def IsRange(x,y,z):
    if x>=0 and y>=0 and z>=0 and x<H and y<N and z<M: return True
    return False

L = [[] for _ in range(H)]

for i in range(H):
    for j in range(N):
        temp = list(map(int,sys.stdin.readline().split())) 
        L[i].append(temp)

queue = deque([])
for i in range(H):
        for j in range(N):
            for k in range(M):
                if(L[i][j][k]==1): queue.append((i,j,k))

if len(queue)==H*M*N:
    print(0)
    exit()

day = 0
while queue:
    day+=1
    for _ in range(len(queue)):
        i,j,k = queue.popleft()
        for x,y,z in zip(dx,dy,dz):
            if(IsRange(i+x,j+y,k+z) and L[i+x][j+y][k+z]==0):
                queue.append((i+x,j+y,k+z))
                L[i+x][j+y][k+z]=day

for i in range(H):
        for j in range(N):
            for k in range(M):
                if(L[i][j][k]==0):
                    print(-1)
                    exit()
                
print(day-1)
