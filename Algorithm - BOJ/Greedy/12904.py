import sys

S = sys.stdin.readline().replace('\n','')
T = sys.stdin.readline().replace('\n','')

flag = 0
temp = T
for _ in range(len(T)):
    if temp[-1]=='A': temp = temp[:len(temp)-1]
    else: temp = temp[:len(temp)-1][::-1]
    if temp==S:
        flag=1
        break

print(flag)
