#your code goes here
test = input() 
for k in range ( 0 , test ) :
	s = raw_input()
	n = input() 
	total = 0 
	for i in range ( 0 , n ) :
		total += input()
	if ( total % n  == 0 ) :
		print "YES"
	else : 
		print "NO"
