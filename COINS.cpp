#include <iostream>
#include <cstdio>
using namespace std;

unsigned int arr[100000010] ;

long long coins ( long long n )
{
  if ( n != 0 )
    {
    	if ( n < 100000000 && arr[n]!=0 )
    		return arr[n] ;
      if ( n > 36 )
	{
	  if ( n < 100000000 )
	  {
	  arr[n] = coins ( n/2 ) + coins (n/3 ) + coins ( n/4) ;
	  return arr[n] ;
	  }
	  else 
	  	return coins(n/2) + coins (n/3) + coins(n/4) ;
	}
      else
	{
	  long long c = coins ( n/2 ) + coins ( n/3 ) + coins ( n/4 ) ;
	  if ( c > n )
	  {
	  	if ( n < 100000000)
	  	{
	  		arr[n] = c ;
	    	return c ;
	  	}
	  	else
	  		return c ;
	  }
	  else
	  	if ( n < 100000000 )
	  		arr[n] = n ;
	    return n ;
	}
    }
  else
    return 0 ;
}

int main()
{
  int n ;
  while ( scanf("%d",&n) !=EOF )
    {
      if ( n < 100000000 )
	{
	arr[n] = coins ( n ) ;
      printf("%u\n",arr[n]) ;
	}
      else
	printf("%lld\n",coins(n) ) ;
    }
  return 0 ;
}
	
	  
   

