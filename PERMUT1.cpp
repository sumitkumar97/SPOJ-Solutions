#include <iostream>
#include <cstdio>
using namespace std ;

int n , k , dp[10000][1000] ;

int rec ( int iter , int state , int inversions ){

  if ( iter > n ){
    if ( inversions == k )
      return 1 ;
    else
      return 0 ;
  }

  if ( dp[state][inversions] != -1 )
    return dp[state][inversions] ;

  int ans = 0 , newinv , newstate ;
  for ( int i = 1 ; i <= n ; i ++ ){
    newinv = inversions ;
    if ( !((1<<i) & state) ){
      for ( int j = i + 1 ; j <= n ; j ++ )
	if ( (1<<j) & state )
	  newinv ++ ;

      newstate = state | (1<<i) ;
      ans += rec ( iter + 1  , newstate , newinv ) ;
    }
  }

  return dp[state][inversions] = ans ;
}


int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    for ( int i = 0 ; i < 10000 ; i ++ )
      for ( int j = 0 ; j < 1000 ; j ++ )
	dp[i][j] = -1 ;
    scanf("%d%d" , &n , &k ) ;
    printf("%d\n" , rec ( 1 , 0 , 0 ) ) ;
  }
  return 0 ;
}
