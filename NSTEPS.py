# your code goes here
test = input()
for i in range (0,test) :
	m , n = raw_input().split(" ")
	x = int (m)
	y = int ( n )
	num = -1
	f = 0
	if ( x == y or x==y+2 ) :
		f = 1
		if ( y % 2 == 0 ) :
			num = 2*y
		else :
			num = (y*2) - 1
	if ( f ==1 ) :
		if ( x == y ) :
			num = num
		else :
			num += 2
	if ( f == 1 ) :
		print num
	else :
		print "No Number"
	
			
