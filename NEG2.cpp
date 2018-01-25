#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

typedef long long ll ;

int ans[40] ;
ll power[40] , sum[40] ;


void rec ( ll n ){
  int i = 0 ;
  if ( n > 0 ){
    while ( sum[i] < n )
      i ++ ;
    n -= power[i] ;
    ans[i] = 1 ;
  }
  else{
    i = 0 ;
    while ( sum[i] > n )
      i ++ ;
    n -= power[i] ;
    ans[i] = 1 ;
  }
  if ( n != 0 )
    rec ( n ) ;
}



int main() {
  ll n ;
  power[0] = 1 ;
  for ( int i = 1 ; i < 40 ; i ++ )
    power[i] = (-2)*power[i-1] ;
  sum[0] = power[0] ;
  sum[1] = power[1] ;
  for ( int i = 2 ; i < 40 ; i ++ )
    sum[i] = sum[i-2] + power[i] ;
  scanf("%lld" , &n ) ;
  if ( !n ){
    printf("0\n") ;
    return 0 ;
  }
  rec ( n ) ;
  bool flag = true ;
  for ( int j = 39 ; j >= 0 ; j -- ){
    if ( flag ){
      if ( ans[j] == 1 )
	flag = false ;
      else
	continue ;
    }
    printf("%d" , ans[j] ) ;
  }
  printf("\n") ;
  return 0 ;
}
