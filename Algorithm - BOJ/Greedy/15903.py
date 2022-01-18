import sys
input = sys.stdin.readline

n,m = map(int,input().split())
L = list(map(int,input().split()))
for _ in range(m):
    L = sorted(L)
    L[0]+=L[1]
    L[1]=L[0]

print(sum(L))
