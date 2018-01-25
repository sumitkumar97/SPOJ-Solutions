# your code goes here
n = input()
while ( n != 0 ) :
	sumit=raw_input()
	x=len(sumit)
	z = 0
	if ( x % n == 0 ) :
		z = x/n
	else :
		z = ( x/n ) + 1
	newcode = [ [0 for x in range ( 0 , n )] for x in range ( 0 , z ) ]
	p=0
	for i in range ( 0 , z ) :
		if ( i % 2 == 0 ) :
			for j in range ( 0 , n ) :
				newcode[i][j]=sumit[p]
				p+=1
		else :
			j=n-1
			while ( j >= 0 ) :
				newcode[i][j]=sumit[p]
				p+=1
				j-=1
	anotherlist = list()
	for j in range ( 0 , n ) :
		for i in range ( 0 , z ) :
			anotherlist.append(newcode[i][j])
	str1="".join(anotherlist)
	print str1
	n=input()
