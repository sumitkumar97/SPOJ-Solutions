#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main() {
  int test ;
  scanf("%d",&test) ;
  char avg[20] ;
  while ( test -- ){
    scanf("%s",avg) ;
    int i = 0 ;
    while ( ! ( avg[i] == '.' || avg[i] == '\0' ) )
      i ++ ;
    int zeroes_in_den = strlen(avg) - 1 - i , twos = 0 , fives = 0 , num = 0 ;
    for ( int j = i + 1 ; j < strlen(avg) ; j ++ )
      num = ( num*10 ) + (int)( avg[j] - '0' ) ;
    while ( num && num % 2 == 0  ){
      num /= 2 ;
      twos ++ ;
    }
    while ( num && num % 5 == 0 ) {
      num /= 5 ;
      fives ++ ;
    }
    int ans = 1 , fives_in_den = zeroes_in_den ;
    while ( zeroes_in_den - twos > 0 ){
      ans *= 2 ;
      zeroes_in_den -- ;
    }
    while ( fives_in_den - fives > 0 ){
      ans *= 5 ;
      fives_in_den -- ;
    }
    printf("%d\n",ans) ;
  }
  return 0 ;
}
    
