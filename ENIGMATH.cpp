#include <iostream>
using namespace std ;

long long gcd ( long long a , long long b ) {
  if ( b == 0 )
    return a ;
  gcd ( b , a%b ) ;
}

int main() {
  ios_base::sync_with_stdio(false) ;
  int test;
  cin>> test ;
  long long a , b , x , y , div ;
  while ( test -- ) {
    cin >> a >> b ;
    div = gcd ( a , b ) ;
    y = a / div ;
    x = b / div ;
    cout<<x<<" "<<y<<"\n" ;
  }
  return 0 ;
}

    
