from collections import defaultdict

n = int(input())
target_x,target_y = map(int,input().split())
m = int(input())
adj = defaultdict(list)
visited = set([target_x])

global flag
flag = True

def dfs(start, depth):
    if start == target_y:
        global flag 
        flag = False
        print(depth)
    for i in adj[start]:
        if i not in visited: 
            visited.add(i)
            dfs(i, depth+1)
    
for _ in range(m): 
    x,y = map(int,input().split())
    adj[x].append(y)
    adj[y].append(x)

dfs(target_x,0)
if flag : print(-1)
