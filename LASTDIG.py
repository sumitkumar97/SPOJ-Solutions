# your code goes here# your code goes here
test = input()

def f ( base , exp ):
	if exp == 0:
		return 1
	
	if exp%2 == 0:
		ans = f(base,exp/2)
		return (ans*ans)%10
	else:
		return (base*f(base,exp-1))%10

for i in range ( 0 , test ) :
	n = raw_input().split(" ")
	base = int ( n[0] )
	exp = int ( n[1] )
	ans = f(base,exp)
	print ans
		
