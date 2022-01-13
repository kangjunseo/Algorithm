n = int(input())
ropes = []
for i in range(n): ropes.append(int(input()))
ans = 0
for i, v in enumerate(sorted(ropes)[::-1]): ans = max(ans,(i+1)*v)
print(ans)
