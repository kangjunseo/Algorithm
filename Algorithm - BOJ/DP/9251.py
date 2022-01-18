import sys
sys.setrecursionlimit(10**4) #preventing recursion error

M = sys.stdin.readline().rstrip()
N = sys.stdin.readline().rstrip()

def LCS(v, w):
    graph = [[0 for _ in range(len(w)+1)] for _ in range(len(v)+1)]
    
    for i in range(1,len(v)+1):
        for j in range(1,len(w)+1):
            match = 0
            if v[i-1] == w[j-1] : match = 1
            graph[i][j] = max(graph[i-1][j],graph[i][j-1],graph[i-1][j-1]+match)
    print(graph[len(v)][len(w)])

LCS(M,N)
 
