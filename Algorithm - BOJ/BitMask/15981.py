# 지금은 수도 비트마스킹인거 같다..
# 제대로 배우고 다시 풀어봐야지..
import sys, math
input = sys.stdin.readline

def binary(n,D):
    if(D==0):
        if n==0: return '0'
        if n==1: return '1'
    return str(n%2)+binary(n//2,D-1)


N = int(input())
D = int(math.log2(N-1))+1
bit = 2**D-1
L = [['' for _ in range(N)] for _ in range(D)]
for j in range(N):
    for i in range(D):
        L[i][j]=binary(bit,D-1)[::-1][i]
    bit -=1

print(D)
for bits in L: 
    print(bits.count('1'),end=' ')
    for i, bit in enumerate(bits):
        if bit == '1': print(i+1, end=' ')
    print()
