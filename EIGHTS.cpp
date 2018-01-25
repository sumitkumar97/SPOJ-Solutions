#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int test ;
  cin>>test ;
  int arr[4] = { 942 , 192 , 442 , 692 } ;
  long long k , i , j ;
  for ( int s = 0 ; s < test ; s ++ )
    {
      cin>>k ;
      i = k % 4 ;
      j = k / 4 ;
      if ( j-1 > 0 && i==0 )
	cout<<j-1 ;
      else if ( j != 0 && i != 0 )
	cout<<j ;
      cout<<arr[i]<<"\n" ;
    }
  return 0;
}
