#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std ;

int main()
{
  int n ;
  cin>>n ;
  char arr[4] ;
  int tq = 0 , h = 0 , oq = 0 ;
  for ( int i = 0 ; i < n; i ++)
    {
      cin>>arr ;
      if ( arr[0] == '1' && arr[2] == '4')
	oq++ ;
      else if ( arr[0] == '3' && arr[2] == '4' )
	tq++ ;
      else if ( arr[0] == '1' && arr[2] == '2' )
	h++ ;
    }
  int ans = 0 ;
  if ( tq >= oq )
    {
      ans += tq ;
      if ( h % 2 == 0 )
	ans += h/2 ;
      else
	ans += h/2 + 1 ;
    }
  else
    {
      ans += tq ;
      oq -= tq ;
      ans += h/2 ;
      if ( h % 2 != 0 )
	{
	  oq -= 2 ;
	  ans ++ ;
	  if (oq > 0 )
	    {
	      if ( oq % 4 == 0 )
		ans += oq/4 ;
	      else
		ans += oq/4 + 1 ;
	    }
	}
      else
	{
	  if ( oq % 4 == 0 )
	    ans += oq/4 ;
	  else
	    ans += oq/4 + 1 ;
	}
    }
  ans ++ ;
  cout<<ans ;
  return 0 ;
}
