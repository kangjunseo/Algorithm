n = int(input())
L = []
cnt = 0
for _ in range(n): L.append(int(input()))
for i in range(n-1,0,-1):
    while(L[i-1]>=L[i]):
        cnt+=1
        L[i-1]-=1
print(cnt)
