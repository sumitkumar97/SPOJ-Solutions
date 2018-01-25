#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int prime[10000010] ;
long long a[10000010] ;

int main() {

    for ( int i = 2 ; i <= 10000000 ; i ++ )
    prime[i] = i ;
  
  for ( int i = 2 ; i <= 3200 ; i ++ ){
    if ( prime[i] == i ){
      for ( int j = 2 ; (i*j) <= 10000000 ; j ++ ){
	if ( prime[i*j] == (i*j) )
	  prime[i*j] = i ;
      }
    }
  }

  a[1] = 0 ;
  for ( int i = 2 ; i <= 10000000 ; i ++ )
    a[i] = a[i-1] + prime[i] ;

  int test , n ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    printf("%lld\n" , a[n] ) ;
  }
  return 0 ;
}
  
