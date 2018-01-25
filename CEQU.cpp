#include <iostream>
#include <cstdio>
using namespace std ;

int gcd ( int a , int b ){
  if ( b == 0 )
    return a ;
  return gcd ( b , a%b ) ;
}

int main() {
  int test , a , b , c , caseno = 1 ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d%d%d" , &a , &b , &c ) ;
    if ( ! ( c % gcd ( a , b ) ) )
      printf("Case %d: Yes\n" , caseno ) ;
    else
      printf("Case %d: No\n" , caseno ) ;
    caseno ++ ;
  }
  return 0 ;
}
