import sys
input = lambda: sys.stdin.readline().strip()

tri_arr=[]
i=1
while(i<=44):
  tri_arr.append(i*(i+1)/2)
  i+=1

N=int(input())
for _ in range(N):
  temp=int(input())
  ans=0
  for i in range(44):
    for j in range (i,44):
      for k in range(j,44):
        if(tri_arr[i]+tri_arr[j]+tri_arr[k]==temp):
          ans=1
          break
  print(ans)
