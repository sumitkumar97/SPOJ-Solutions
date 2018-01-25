# your code goes here
s = raw_input()
n = float(s)
length = list()
i = 0
length.append(0)
while ( length[i]<=5.20 ) :
    i+=1
    length.append((length[i-1])+(float(1)/(i+1)))
    f = 0
    while ( n != 0.00 ) :
        for j in range ( 1 , i ) :
        if ( length[j] >= n ) :
    f =1
    break
if ( f == 1 ) :
print j,"card(s)"
s = raw_input()
n = float(s)
