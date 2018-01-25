# your code goes here
test = input()
def fact ( k ) :
	if ( k == 0 ) :
		return 1
	else :
		return k * fact(k-1)
for i in range ( 0 , test ) :
	n = input()
	print(fact(n))
