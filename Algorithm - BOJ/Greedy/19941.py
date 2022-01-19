import sys
input = sys.stdin.readline

N, K = map(int,input().split())
bench = input().rstrip('\n')
ate = set()
cnt = 0

for i in range(N):
    for k in range(-K,K+1):
        if K==0: continue
        if bench[i]=='P' and not i in ate: 
            if 0<=i+k<N and i+k not in ate and bench[i+k]=='H':
                ate.add(i+k)
                ate.add(i)
                cnt += 1
                continue
    
print(cnt)
