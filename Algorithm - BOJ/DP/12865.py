import sys

N,K = map(int,sys.stdin.readline().split())
L = []
for _ in range(N): L.append(list(map(int,sys.stdin.readline().split())))
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1,N+1):
    for j in range(1,K+1):
        if j>=L[i-1][0]: dp[i][j] = max(dp[i-1][j],dp[i-1][j-L[i-1][0]]+L[i-1][1])
        else: dp[i][j] = dp[i-1][j]
            
print(dp[N][K])
