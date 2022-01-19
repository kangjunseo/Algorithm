import sys
input = sys.stdin.readline

N = int(input())
L = []
for _ in range(N): L.append(int(input()))
L = sorted(L)[::-1]
money = sum(L)
for i in range(2,N,3): money -=L[i]

print(money)
