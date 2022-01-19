import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N = int(input())
    S = input().rstrip()
    E = input().rstrip()
    score = 0
    mismatch = 0
    diff = abs(S.count('W')-E.count('W'))
    for s,e in zip(S,E): 
        if s!=e: mismatch+=1
    
    print(int((mismatch+diff)/2))
