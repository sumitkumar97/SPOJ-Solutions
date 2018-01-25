#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  // your code goes here
  int test ;
  long long arr[20010] , n , k , min , temp  ;
  cin>>test ;
  for ( int t = 0 ; t < test ; t ++ )
    {
      cin>>n>>k ;
      min = 1000000000 ;
      for ( int i = 0 ; i < n ; i ++ )
	{
	  cin>>arr[i] ;
	}
      sort(arr, arr+n);
      int s = 0 ;
      while ( s+k <= n )
	{
	  temp = arr[s+k-1] - arr[s] ;
	  if ( temp < min )
	    min = temp ;
	  s++ ;
	}
      cout<<min<<"\n" ;
    }
  return 0;
}
