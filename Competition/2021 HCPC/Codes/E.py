L=[]
P=[]

def check(md):
    if(md>=120 and md<=218):
        return 'A'
    if(md>=219 and md<=320):
        return 'B'
    if(md>=321 and md<=419):
        return 'C'
    if(md>=420 and md<=520):
        return 'D'
    if(md>=521 and md<=621):
        return 'E'
    if(md>=622 and md<=722):
        return 'F'
    if(md>=723 and md<=822):
        return 'G'
    if(md>=823 and md<=922):
        return 'H'
    if(md>=923 and md<=1022):
        return 'I'
    if(md>=1023 and md<=1122):
        return 'J'
    if(md>=1123 and md<=1221):
        return 'K'
    return 'L'

for i in range(7):
    tempM, tempD = map(int,input().split())
    L.append(check(100*tempM+tempD))

N = int(input())
for i in range(N):
    tempM, tempD = map(int,input().split())
    if check(100*tempM+tempD) in L:
        pass
    else: P.append(100*tempM+tempD)

P = sorted(P)
if P==[]:
    print('ALL FAILED')
else:
    for i in P:
        print(i//100,i-100*(i//100))
    
