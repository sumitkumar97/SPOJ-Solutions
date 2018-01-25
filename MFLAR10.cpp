#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std ;

int main() {
  char arr[3000] ;
  fgets ( arr , 2500 , stdin ) ;
  while ( arr[0] != '*' ) {
    char ans = 'Y' ;
    for ( int i = 1 ; i < strlen(arr) ; i ++ ){
      if ( arr[i] == ' ' ){
	if ( arr[i+1] != arr[0] && abs ( arr[i+1] - arr[0] ) != 32 ) {
	  ans = 'N' ;
	}
      }
    }
    printf("%c\n",ans) ;
    fgets ( arr , 2500 , stdin ) ;
  }
  return 0 ;
}
