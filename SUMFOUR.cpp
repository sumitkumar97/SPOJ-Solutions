#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int x[6250010] , y[6250010] ;

int main() {
  int n , a[2510] , b[2510] , c[2510] , d[2510] , xcount = 0 , ycount = 0 ;
  scanf("%d" , &n ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%d%d%d%d" , &a[i] , &b[i] , &c[i] , &d[i] ) ;

  for ( int i = 0 ; i < n ; i ++ )
    for ( int j = 0 ; j < n ; j ++ ){
      x[xcount] = a[i] + b[j] ;
      xcount ++ ;
      y[ycount] = c[i] + d[j] ;
      ycount ++ ;
    }
  sort ( y , y + ycount ) ;
  int lowerindex , upperindex ;
  long long ans = 0 ;
  for ( int i = 0 ; i < xcount ; i ++ ){
    lowerindex = lower_bound ( y , y + ycount , -x[i] ) - y ;
    upperindex = upper_bound ( y , y + ycount , -x[i] ) - y ;
    
    ans += upperindex - lowerindex ;
  }
  printf("%lld\n" , ans ) ;
  return 0 ;
}
