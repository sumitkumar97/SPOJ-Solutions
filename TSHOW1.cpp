#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test ;
  scanf("%d",&test) ;
  long long arr[60] ;
  long long temp = 1 ;
  for ( int i = 1 ; i < 54 ; i ++ ) {
    temp <<= 1 ;
    arr[i] = temp - 1 ;
  }
  long long powersoftwo[60] ;
  powersoftwo[0] = 1 ;
  for ( int i = 1 ; i < 54 ; i ++ )
    powersoftwo[i] = powersoftwo[i-1]*2 ;
  while ( test -- ) {
    long long k ;
    scanf("%lld",&k) ;
    int i = 1 ;
    while ( arr[i] <= k )
      i ++ ;
    i -- ;
    char a[60] ;
    for ( int j = 0 ; j < i ; j ++ ){
      a[j] = '5' ;
    }
    k -= arr[i] ;
    int change = 53 ;
    while ( k < powersoftwo[change] ){
      change --  ;
    }
    while ( k ){
      a[change] = '6' ;
      k -= powersoftwo[change] ;
      while ( k < powersoftwo[change] )
	change -- ;
    }
    for ( int j = i - 1 ; j >= 0 ; j -- )
      printf("%c",a[j]) ;
    printf("\n") ;
  }
  return 0 ;
}
