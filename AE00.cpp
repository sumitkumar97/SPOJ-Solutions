#include <iostream>
#include <cmath>
using namespace std ;

int main()
{
  int n , ans=0 , i , j ;
  cin>>n ;
  for ( i = n ; i >= 1 ; i -- )
    {
      for ( j = 1 ; j <= sqrt(i) ; j ++ )
	{
	  if(i%j == 0 )
	    //{cout<<sqrt(n)<<i<<"%"<<j<<endl ;
	    ans++ ;
	  // }
	}
      //cout<<ans<<endl ;
    }
  cout<<ans ;
  return 0 ;
}

