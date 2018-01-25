#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int n , arr[1500] ;
  scanf("%d",&n) ;
  while ( n ){
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d",&arr[i]) ;
    sort ( arr , arr + n ) ;
    int fuel = 200 , possible = 1 , prevdist = 0 ;
    for ( int i = 1 ; i < n ; i ++ ){
      fuel -= arr[i] - prevdist ;
      prevdist = arr[i] ;
      if ( fuel < 0 ) {
	possible = 0 ;
	break ;
      }
      fuel = 200 ;
    }
    if ( possible ){
      if ( (1422 - prevdist)<<1 > 200 )
	printf("IMPOSSIBLE\n") ;
      else
	printf("POSSIBLE\n") ;
    }
    else
      printf("IMPOSSIBLE\n") ;
    scanf("%d",&n) ;
  }
  return 0 ;
}
