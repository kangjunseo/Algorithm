import sys
from collections import deque

F,S,G,U,D = map(int,sys.stdin.readline().split())
visited = [0 for _ in range(F+1)]

def bfs():
    queue = deque([S])
    visited[S] = 1
    while queue:
        x = queue.popleft()
        if x==G: break
        if 1<=x+U<=F and visited[x+U]==0:
            queue.append(x+U)
            visited[x+U]=visited[x]+1
        if 1<=x-D<=F and visited[x-D]==0:
            queue.append(x-D)
            visited[x-D]=visited[x]+1
bfs()
if visited[G]==0: print('use the stairs')
else: print(visited[G]-1)
