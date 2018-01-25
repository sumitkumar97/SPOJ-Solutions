#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n , row ;
  char p[] = { 'W' , 'A' , 'A' , 'M' , 'W' } , d ;
  scanf("%d", &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    if ( n == 1 ){
      printf("poor conductor\n") ;
      continue ;
    }
    row = ( n + 3 )/5 ;
    if ( row % 2 ){
      d = ((n+3)%5) < 2 ? 'L' : 'R' ;
      printf("%d %c %c\n" , row , p[(n+3)%5] , d ) ;
    }
    else{
      d = ((n+3)%5) < 3 ? 'R' : 'L' ;
      printf("%d %c %c\n" , row , p[4 - ((n+3)%5) ] , d ) ;
    }
  }
  return 0 ;
}
