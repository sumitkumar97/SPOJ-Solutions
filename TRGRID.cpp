#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test-- ) {
    int r , c ;
    scanf("%d%d",&r,&c) ;
    if ( r > c ) {
      if ( c % 2 )
	printf("D\n") ;
      else
	printf("U\n") ;
    }
    else if ( r == c ) {
      if ( r % 2 )
	printf("R\n") ;
      else
	printf("L\n") ;
    }
    else {
      if ( r % 2 )
	printf("R\n") ;
      else
	printf("L\n") ;
    }
  }
  return 0 ;
}
      
