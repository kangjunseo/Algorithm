S = input()
A = ''

for i in range(len(S)):
    if(i==len(S)-1):
        A+=S[i]
    else:
        A+=S[i]+'__'

print(A)
