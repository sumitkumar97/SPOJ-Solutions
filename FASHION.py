# your code goes here
# your code goes here
test = input()
for i in range ( 0 , test ) :
	n = input()
	first = raw_input().split(" ")
	second = raw_input().split(" ")
	m = list ()
	w = list ()
	sum = 0
	for i in range ( 0 , n ) :
		m.append(int(first[i]))
		w.append(int(second[i]))
	m.sort()
	w.sort()
	for i in range ( 0 , n ) :
		sum += m[i]*w[i]
	print sum
	
		
