import sys

I = sys.stdin.readline().split()
A = sorted(map(int,sys.stdin.readline().split()))[::-1]
B = sorted(map(int,sys.stdin.readline().split()))
ans = 0 
for a,b in zip(A,B):
    ans+=a*b

print(ans)
