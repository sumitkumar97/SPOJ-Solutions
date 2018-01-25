# your code goes here
test = input()
for k in range ( 0 , test ) :
    t = input()
    i = 1
    sum = 0
    while ( 1 ) :
    sum += i
if (sum >= t ) :
    break
i += 1
j = t - ( sum - i )
k = i + 1
if i % 2 == 0 :
print("TERM %d IS %d/%d")%(t,j,k-j)
else :
print ("TERM %d IS %d/%d")%(t,k-j,j)
