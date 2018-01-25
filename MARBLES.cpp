#include <iostream>
using namespace std ;

int main()
{
  int test ;
  long long n , k , z , ans=1 ;
  cin>>test ;
  for ( int t = 0 ; t < test ; t ++ )
    {
      cin>>n>>k ;
      ans = 1 ;
      n -= 1 ;
      k -= 1 ;
      if ( n - k < k )
	z = n- k ;
      else
	z = k ;
      for ( int i = 0 ; i < z  ; i ++ )
	{
	  ans = (ans*(n-i))/(i+1) ;
	}
      cout<<ans<<"\n" ;
    }
  return 0 ;
}
