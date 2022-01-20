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

L = []
while 1:
    string = input().rstrip('\n')
    if string=='.': break
    else: L.append(string)

for string in L: 
    flag = pattern_table(string)[-1]
    l = len(string)
    if l%(l-flag): print(1)
    else: print(l//(l-flag))
