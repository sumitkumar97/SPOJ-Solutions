#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int main()
{
  int n , i , test , a[100010]={0} ;
  scanf("%d",&test) ;
  for ( i = 2 ; i <= 100000 ; i ++ )
    {
      if(a[i] == 0 )
	{
	  int  x= 2 ;
	  while ( x*i <= 100000 )
	    {
	      a[x*i] = 1 ;
	      x++ ;
	    }
	}
    }
  int j = 0 , prime[100000]  ;
  for ( i = 2 ; i <= 100000 ;i ++)
    {
      if ( a[i] == 0 )
	{
	  prime[j] = i ;
	  j++ ;
	}
    }
  int s ;
  for (int k = 0 ; k < test ; k ++ )
    {
      scanf("%d",&n) ;
      s = j - 1 ;
      int no = n ;
      long long ans = n ;
      for ( i = 0 ; i <= s ; i++)
	{
	  if ( i*i > n )
	    break ;
	  if ( n==1 || prime[i] > no )
	    break ;
	  if ( n % prime[i] == 0 )
	    {
	      ans *= prime[i]-1 ;
	      ans /= prime[i] ;
	      while ( n % prime[i] == 0 )
		{
		  n/= prime[i] ;
		}
	    }
	}
      if ( n > 1)
	{
	  ans *= n -1 ;
	  ans /= n ;
	}
      printf("%d\n",ans) ;
    }
  return 0 ;
}



