#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std ;

int main() {
  char s[1010] ;
  int a , b ;
  while ( scanf("%s", s ) != EOF ){
    a = 0 , b = 0 ;
    bool flag = false ;
    for ( int i = 0 ; i < strlen(s) ; i ++ ){
      if ( islower ( s[i] ) && flag ) // upper for true flag
	a ++ ;
      if ( isupper ( s[i] ) && !flag ) // lower for false flag
	a ++ ;
      flag = !flag ;
    }
    flag = true ;
    for ( int i = 0 ; i < strlen(s) ; i ++ ){
      if ( islower ( s[i] ) && flag ) // upper for true flag
	b ++ ;
      if ( isupper ( s[i] ) && !flag ) // lower for false flag
	b ++ ;
      flag = !flag ;
    }
    printf("%d\n" , min ( a , b ) ) ;
  }
  return 0 ;
}
