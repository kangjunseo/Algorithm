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

def KMP(string, pattern):
    kmp = []
    table = pattern_table(pattern)
    strsize = len(string)
    patsize = len(pattern)
    j = 0
    for i in range(strsize):
        while j>0 and string[i]!=pattern[j]: j = table[j-1]
        if string[i]==pattern[j]:
            if j==patsize-1: 
                kmp.append(i-patsize+2)
                j = table[j]
            else: j+=1
    
    return kmp

T = input().rstrip('\n')
P = input().rstrip('\n')
kmp = KMP(T,P)
print(len(kmp))
for i in kmp: print(i, end=' ')
