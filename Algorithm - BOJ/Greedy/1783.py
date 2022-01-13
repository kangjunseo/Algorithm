import sys
#개씹빡구현...
A,B = map(int,sys.stdin.readline().split())
if A==1: print(1)
elif A==2: print(min(4,(B+1)//2))
elif B<7: print(min(4,B))
else: print(B-2)
