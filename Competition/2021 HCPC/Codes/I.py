L=[]
bonus=0
for i in range(10): 
    t= input()
    if(t==''):break
    temp = int(t)
    if temp == 111 or temp == 1011 or temp == 1110 or temp == 1101:
        L.append(1)
    elif temp == 11  or temp == 101 or temp == 1001  or temp == 1100  or temp == 1010 or temp == 110:
        L.append(2)
    elif temp == 1 or temp == 1000 or temp == 100 or temp == 10:
        L.append(3)
    elif temp == 1111:
        L.append(4)
        bonus+=1
    elif temp == 0:
        L.append(5)
        bonus+=1
    else:
        break

while(bonus>0):
    t= input()
    if(t==''):break
    temp = int(t)
    if temp == 111 or temp == 1011 or temp == 1110 or temp == 1101:
        L.append(1)
    elif temp == 11  or temp == 101 or temp == 1001  or temp == 1100  or temp == 1010 or temp == 110:
        L.append(2)
    elif temp == 1 or temp == 1000 or temp == 100 or temp == 10:
        L.append(3)
    elif temp == 1111:
        L.append(4)
        bonus+=1
    elif temp == 0:
        L.append(5)
        bonus+=1
    else:
        break
    bonus-=1

win=False
stat = 0
firstP = False
midP = False
lastP = False
for i in L:
    stat+=i
    
    if(stat==5):
        firstP=True
    elif(firstP and stat==8):
        midP=True
    elif(not firstP and stat==10):
        lastP=True

    if(midP and stat>=12):
        win=True
        break
    elif(firstP and not midP and stat>=17):
        win=True
        break
    elif(lastP and stat>=17):
        win=True
        break
    elif(stat>=21):
        win=True
        break

if(win):
    print('WIN')
else:
    print('LOSE')
         
