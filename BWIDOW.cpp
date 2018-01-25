#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n , ir[1010] , outerr[1010] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    int maxir = 1 ;
    for ( int i = 1 ; i <= n ; i ++ ){
      scanf("%d%d" , &ir[i] , &outerr[i] ) ;
      if ( ir[i] > ir[maxir] )
	maxir = i ;
    }
    bool ans = true ;
    for ( int i = 1 ;i <= n ; i ++ ){
      if ( i != maxir && outerr[i] > ir[maxir] ){
	ans = false ;
	break ;
      }
    }
    if ( ans )
      printf("%d\n" , maxir ) ;
    else
      printf("-1\n") ;
  }
  return 0 ;
}
