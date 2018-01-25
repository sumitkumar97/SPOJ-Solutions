#include <stdio.h>

int main(void) {
	// your code goes here
	int n , no ;
	scanf("%d",&n) ;
	while ( n!=0 )
	{
		printf("%d\n",(n*(n+1)*((2*n)+1))/6 ) ;
		scanf("%d",&n) ;
	}
	return 0;
}

