#include <iostream>
#include <cstdio>
using namespace std ;

typedef long long ll ;

int main() {
  int n ,k , caseno = 1 ;
  ll c[1010] , x ;
  scanf("%d" , &n ) ;
  while ( n != -1 ){
    ll ans ;
    for ( int i = n ; i >= 0 ; i -- )
      scanf("%lld" , &c[i] ) ;
    scanf("%d" , &k ) ;
    printf("Case %d:\n" , caseno ) ;
    for ( int i = 0 ;i < k ; i ++ ){
      ans = c[0] ;
      scanf("%lld" , &x ) ;
      ll tempx = x ;
      for ( int j = 1 ; j <= n ; j ++ ){
	ans += c[j]*tempx ;
	tempx *= x ;
      }
      printf("%lld\n" , ans ) ;
    }
    scanf("%d" , &n ) ;
  caseno ++ ;
  }
  return 0 ;
}
