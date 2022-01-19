import sys
input = sys.stdin.readline

T = int(input())
fb = [0 for _ in range(50)]
fb[0], fb[1] = 1,1
for i in range(2,50): fb[i] = fb[i-1]+fb[i-2]

for _ in range(T):
    N = int(input())
    L = []
    while N:
        for i in range(50):
            if fb[i]>N: 
                L.append(fb[i-1])
                N-=fb[i-1]
                break
            if fb[i]==N:
                L.append(fb[i])
                N=0
                break
    for i in sorted(L): print(i, end=' ')
    print()
