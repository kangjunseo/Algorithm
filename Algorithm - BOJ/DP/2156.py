import sys

n = int(sys.stdin.readline())
L = []
for _ in range(n): L.append(int(sys.stdin.readline()))
dp = [[0 for _ in range(2)] for _ in range(n)]
dp[0][0] = L[0]
if n>1: 
    dp[1][0] = L[0]+L[1]
    dp[1][1] = L[0]
for i in range(2,n):
    dp[i][0] = L[i] + max(dp[i-1][1], dp[i-2][0], dp[i-2][1]+L[i-1])
    dp[i][1] = max(dp[i-1][1],dp[i-1][0])
    
print(max(dp[n-1]))
