import sys
input = sys.stdin.readline

def pattern_table(pattern):
    size = len(pattern)
    table = [0 for _ in range(size)]
    j = 0
    for i in range(1,size):
        while j>0 and pattern[i]!=pattern[j]: j = table[j-1]
        if pattern[i]==pattern[j]:
            j+=1
            table[i]=j
    return table

L = int(input())
ad = input().rstrip('\n')
print(L-pattern_table(ad)[-1])
