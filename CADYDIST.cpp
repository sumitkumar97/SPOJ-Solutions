#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  long long n , c[100010] , p[100010] , ans ;
  scanf("%lld",&n) ;
  while ( n ) {
    ans = 0 ;
    for ( int i = 0 ; i < n ;  i ++ )
      scanf("%lld",&c[i]) ;
    for ( int i = 0 ; i <  n ; i ++ )
      scanf("%lld",&p[i]) ;
    sort ( c , c + n ) ;
    sort ( p , p + n ) ;
    for ( int i = 0 ; i < n ; i ++ )
      ans += c[i]*p[n-1-i] ;
    printf("%lld\n",ans) ;
    scanf("%lld",&n) ;
  }
  return 0 ;
}

    
