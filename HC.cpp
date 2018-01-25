#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n , l , h ;
  char s[5] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    l = 0 , h = 0 ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%s" , s ) ;
      if ( s[0] == 'l' )
	l ++ ;
      else
	h ++ ;
    }
    bool lwins = true ;
    if ( l % 2 == 0 )
      lwins = false ;
    if  ( lwins )
      printf("lxh\n") ;
    else
      printf("hhb\n") ;
  }
  return  0 ;
}
