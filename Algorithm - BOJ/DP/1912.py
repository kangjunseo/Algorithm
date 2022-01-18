import sys

n = int(sys.stdin.readline())
L = list(map(int, sys.stdin.readline().split()))
dp = [0 for _ in range(n)]

dp[0] = L[0]
for i in range(n-1): dp[i+1] = max(L[i+1], dp[i]+ L[i+1])

print(max(dp))
