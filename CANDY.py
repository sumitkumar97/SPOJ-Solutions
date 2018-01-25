# your code goes here
n = input()
while ( n != -1 ) :
	candy = list()
	total = 0
	count = 0
	for i in range ( 0 , n ) :
		candy.append ( input() )
	for i in range ( 0 , n ) :
		total += candy[i]
	if ( total % n == 0 ) :
		for i in range ( 0 , n ) :
			x = total / n
		for i in range ( 0 , n ) :
			if ( candy[i] < x ) :
				count += (x-candy[i])
		print count
	else :
		print "-1"
	n = input()
		
