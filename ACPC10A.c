#include <stdio.h>

int main(void) {
	// your code goes here
	int a , b , c , d ;
	scanf("%d%d%d",&a,&b,&c) ;
	while ( a!=0 || b!=0 || c!=0 )
	{
		if ( (a+c) == (2*b) )
		{
			d=c+(c-b) ;
			printf("AP %d\n",d) ;
		}
		else
		{
			d=c*(c/b) ;
			printf("GP %d\n",d) ;
		}
		scanf("%d%d%d",&a,&b,&c) ;
	}
	return 0;
}

