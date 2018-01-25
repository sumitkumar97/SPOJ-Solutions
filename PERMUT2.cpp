#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int n ;
  cin>>n ;
  while ( n != 0 )
    {
      int arr[n+2] , f = 0 , i ;
      for ( i = 1 ; i <= n ; i ++ )
	{
	  cin>>arr[i] ;
	}
      for ( i = 1 ; i <= n ; i ++ )
	{
	  if ( arr[arr[i]] == i )
	    {
	      f = 1 ;
	    }
	  else
	    {
	      f = 0 ;
	      break ;
	    }
	}
      if ( f == 1 )
	{
	  cout<<"ambiguous\n" ;
	}
      else
	{
	  cout<<"not ambiguous\n" ;
	}
      cin>>n ;
    }
  return 0;
}
