#include <cstdio>
using namespace std ;
long long int a[1000000] , ans ;
int main()
{
  int test ;
  scanf("%d",&test) ;
  //printf("%d\n",test ) ;
  char s[1000000] , b[1000000]  ;
  gets(s) ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      gets(s) ;
      gets(s) ;
      //puts(s) ;
      int i = 0 ; int j = 0 , l = 0 ;
      while ( 1 )
	{
	  a[j] = 0 ;
	  if ( s[i] == ' ')
	    {
	      while ( s[i] == ' ')
		{
		  i ++ ;
		}
	    }
	  while ( ! ( s[i] == ' ' ||  s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == '%' ) )
	    {
	      //printf("s[i] = %c , (int)s[i] = %d\n",s[i] , (int)s[i] - 48 ) ;
	      a[j] = (a[j]*10) + ( (long long int )s[i] - 48 ) ;
	      //printf("a[j] = %d\n",a[j]) ;
	      i++ ;
	    }
	  //printf("final a[j] = %d\n",a[j] ) ;
	  j++ ;
	  if ( s[i] == ' ')
	    {
	      while ( s[i] == ' ')
		{
		  i += 1 ;
		}
	    }
	  if ( s[i] == '=' )
	    break ;
	  b[l] = s[i] ;
	  //printf("%c\n",s[i]) ;
	  l++ ;
	  i++ ;
	}
      switch ( b[0] )
	{
	case '*' :
	  ans = a[0]*a[1] ;
	  break ;
	case '/' :
	  ans = a[0]/a[1] ;
	  //printf("a[0] = %dfuck you a[1] = %d\n",a[0],a[1]) ;
	  break ;
	case '+' :
	  ans = a[0]+a[1] ;
	  break ;
	case '%' :
	  ans =a[0]%a[1] ;
	  break ;
	default :
	  ans = a[0]-a[1] ;
	}
      //if ( ans < 0 )
      //ans *= -1 ;
      //printf("%lld\n",ans) ;
      for ( i = 1 ; i < l ; i ++ )
	{
	  switch ( b[i] )
	    {
	    case '*' :
	      ans *= a[i+1] ;
	      break ;
	    case '/':
	      ans /= a[i+1] ;
	      break ;
	    case '+' :
	      ans += a[i+1] ;
	      break ;
	    case '%' :
	      ans %= a[i+1] ;
	      break ;
	    default :
	      ans -= a[i+1] ;
	    }
	  //if ( ans < 0 )
	  //ans *= -1 ;
	  //printf("%lld\n",ans) ;
	}
      printf("%lld\n",ans) ;
    }
  return 0 ;
}


