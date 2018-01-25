#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int po2[100] , temp ;
  int i = 0 ;
  temp = 1 ;
  while ( temp < 99000001 ) {
    po2[i] = temp ;
    i++ ;
    temp *= 2 ;
  }
  po2[i] = temp ;
  i ++ ;
  char string4[5] ;
  int n ;
  scanf("%s",string4) ;
  while ( ! (string4[0] == '0' && string4[1] == '0' && string4[3] == '0' ) ) {
    n = ( string4[0] - '0' )*10 + ( string4[1] - '0' ) ;
    int lim = string4[3] - '0';
    while ( lim -- ) {
      n *= 10 ;
    }
    int j = 0 ;
    while ( po2[j] <= n ) {
      j++ ;
    }
    n = n - po2[j-1] ;
    printf("%d\n",(2*n)+1) ;
    scanf("%s",string4) ;
  }    
  return 0 ;
}
