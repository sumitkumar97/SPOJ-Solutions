#include <iostream>
#include <cstdio>
using namespace std ;

inline unsigned long long sum ( unsigned long long n ){
  return (n*(n+1))>>1 ;
}

int main() {
  int test ;
  unsigned long long h , ans , n ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%llu" , &h ) ;
    n = (h>>1) + h/6 ;
    ans = n + sum ( h - n - 1 ) ;
    n = h - ( h - n ) - 1 ;
    if ( n%2 )
      ans += ((n>>1))*((n>>1)+1) ;
    else
      ans += (n>>1)*(n>>1) ;
    if ( h <= 1 )
      ans = 0 ;
    printf("%llu\n" , ans ) ;

  }
  return 0 ;
}
