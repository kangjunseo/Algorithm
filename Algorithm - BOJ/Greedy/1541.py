import sys

I = sys.stdin.readline().replace('\n','').split('-')
ans = 0
for idx, i in enumerate(I):
    temp = list(map(int,i.split('+')))
    if idx==0: ans+=sum(temp)
    else: ans-=sum(temp)

print(ans)
