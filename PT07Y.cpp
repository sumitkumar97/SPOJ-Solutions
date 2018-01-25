#include <iostream>
using namespace std;
int arr[10001] ;
int main() {
  // your code goes here
  int m , n ;
  cin>>n>>m ;
  int a[m] , b[m] ;
  for ( int i = 0 ; i < m ; i ++ )
    {
      cin>>a[i]>>b[i] ;
    }
  int f = 1 ;
  if ( n == 1 && m == 0 )
    {
      cout<<"YES" ;
      return 0 ;
    }
  if ( n - 1 == m )
    {
      for ( int i = 0 ; i < m ; i ++ )
	{
	  if ( arr[a[i]] == 0 || arr[b[i]] == 0 )
	    {
	      f = 1 ;
	      arr[a[i]] = 1 ;
	      arr[b[i]] = 1 ;
	    }
	  else
	    {
	      f = 0 ;
	      break ;
	    }
	}
      if ( f == 0 )
	cout<<"NO" ;
      else
	cout<<"YES" ;
    }
  else
    cout<<"NO" ;
  return 0;
}
