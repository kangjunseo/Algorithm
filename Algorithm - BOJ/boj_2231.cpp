N=int(input())
A = []
for i in range(1,N+1):
  A.append(i)
  for n in str(i):
    A[i-1]+=int(n)  

for i in range(1,N+1):
  if (A[i-1]==N):
    print(i)
    quit(0);

print(0)
