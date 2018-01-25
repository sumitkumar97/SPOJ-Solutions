#include <iostream>
#include <cstdio>

int main()
{
  long long n , b ;
  long long a[100000] ;
  scanf("%lld",&n) ;
  long long i , flag = 0 , count = 0  , f = 0  ;
  while ( flag == 0 )
    {
      b = 0 ;
      while ( n != 0 )
	{
	  b += (n%10)*(n%10) ;
	  n/=10 ;
	}
      n = b ;
      a[f] = n ;
      f++ ;
      //printf("%lld\n",n) ;
      count ++ ;
      if ( n == 1 )
	flag = 1 ;
      for ( i = 0 ; i < f-1 ; i ++ )
	{
	  if ( n == a[i] )
	    {
	      flag = 2 ;
	      break ;
	    }
	}
    }
  if ( flag == 2 )
    printf("-1") ;
  if (flag == 1 )
    printf("%lld",count) ;
  return 0 ;
}


