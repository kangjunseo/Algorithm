N,M = map(int,input().split())
arr = []
dp = [[0 for _ in range(N+1)] for _ in range(M+1)]
max_score = 0

for _ in range(M):
	arr.append(list(map(int, input().split())))

for i in range(N):
    for j in range(M):
        temp = 0
        for k in range(M):
            if(i>0 and j==k):
                temp = max(dp[k][i-1]+arr[j][i]//2,temp)
            else:
                temp = max(dp[k][i-1]+arr[j][i],temp)
        dp[j][i]=temp

for i in range(M):
    max_score = max(max_score,dp[i][N-1])

print(max_score)
