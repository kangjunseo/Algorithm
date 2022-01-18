import sys
input = sys.stdin.readline

N = int(input())
K = int(input())
L = sorted(map(int, input().split()))
dist = [0 for _ in range(N-1)]

for i in range(N-1): dist[i] = L[i+1]-L[i]
print(sum(sorted(dist)[::-1][K-1:]))
