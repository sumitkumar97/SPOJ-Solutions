#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int main() {
  int test , m , n , lim = sqrt ( (int)1e9 ) + 1 ;

  bool prime[lim + 10] = {false} ;
  for ( int i = 2 ; i <= sqrt(lim) + 1 ; i ++ )
    for ( int j = 2 ; (i*j) <= lim ; j ++ )
      if ( !prime[i] )
	prime[i*j] = true ;
  
  int numbers[lim] , count = 0 ;
  for ( int i = 2 ; i <= lim ; i ++ )
    if ( !prime[i] ){
      numbers[count] = i ;
      count ++ ;
    }

  scanf("%d" , &test ) ;
  while ( test -- ){
    bool print ;
    scanf("%d%d" , &m , &n ) ;
    if ( m == 1 ) m ++ ;
    for ( ; m <= n ; m ++ ){
      print = true ;
      for ( int i = 0 ; i < count && numbers[i] <= sqrt(m); i ++ )
	if ( m % numbers[i] == 0 ){
	  print = false ;
	  break ;
	}
      if ( print )
	printf("%d\n" , m ) ;
    }
    printf("\n") ;
  }
  return 0 ;
}
