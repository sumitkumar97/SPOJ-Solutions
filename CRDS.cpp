#include <iostream>
using namespace std ;

long long arr[1000001] ;
int main() {
  // your code goes here
  int test ;
  cin>>test ;
  long long n ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      cin>>n ;
      if ( arr[n] <= 0 )
	{
	  arr[n] = 3 * ((n * (n + 1))/2) - n;
	}
      cout<<arr[n]%1000007<<"\n" ;
    }
  return 0;
}
