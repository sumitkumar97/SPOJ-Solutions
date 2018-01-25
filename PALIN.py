# your code goes here
test = input()
for k in range ( 0 , test ) :
    n = raw_input()
    nod = len(n)
    mid = 0
    case = 0
    z = 0
    if ( nod % 2 == 0 ) :
    mid = nod/2 - 1
    else :
    mid = nod/2 -1
case = 1
s = list()
for i in range ( 0 , nod ) :
s.append(int(n[i]))
if ( nod == 1 and s[0] == 9 ):
print "11"
else :
if ( case == 0 ) :
    b = mid+1
else :
    b = mid + 2
f = mid
t = 0
while ( f >= 0 ) :
    if ( s[f] > s[b] ) :
        t = 1
        break
    elif ( s[f] < s[b] ) :
        t = -1
        break
    b += 1
    f -= 1
if ( t <= 0 ) :
    if ( case == 0 ) :
        x = mid
        if ( s[x] == 9 ) :
            while ( x>=0 and s[x]==9 ) :
                t=s[x]
                s[x] = 0
                x-=1
if ( x >= 0 ) :
s[x]+=1
else :
s[x+1] += t+1
z =1
else :
    s[mid]+=1
else :
if ( s[mid+1] == 9 ) :
    x = mid+1
    while ( x>=0 and s[x]==9 ) :
t=s[x]
s[x] = 0
x-=1
if ( x >= 0 ) :
s[x] += 1
else :
s[x+1] += t+1
z = 1
else :
    s[mid+1]+=1
f = mid
if ( case == 0 ) :
    b=mid+1
else :
    b = mid+2
while ( b < nod ) :
    s[b] = s[f]
    b += 1
    f -= 1
if ( z == 1 ) :
    s[nod-1]-=9
print ''.join(str(e) for e in s)






