import sys
input = sys.stdin.readline

arr=[]
for i in range(9):
  arr.append(int(input()))

S=sum(arr)
for i in range(9):
  for j in range (i+1,9):
    if(S-arr[i]-arr[j]==100):
      del(arr[i])
      del(arr[j-1])
      arr.sort()
      for k in arr:
        print(k)
      quit(0);
