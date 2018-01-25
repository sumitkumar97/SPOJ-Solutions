#include <iostream>
#include <cstring>
using namespace std ;

char arr[300] ;


int gcd(int a, int b )
{
  if (b==0)
    return a;
  else {
    return gcd(b,a%b );
  }
}

int main() {
  int n ;
  cin>>n ;
  int ans , a;
  while ( n -- ) {
    cin >> a ;
    cin >> arr ;
    int rem = 0 ;
    int len = strlen(arr) ;
    if ( a != 0 ) {
      for ( int i = 0 ; i < len ; i ++ )
	rem = ( (rem * 10) + ( arr[i] - '0' )) % a ;
      ans = gcd(a , rem) ;
      cout<<ans<<"\n" ;
    }
    else
      cout<<arr<<"\n" ;
  }
  return 0 ;
}

 
