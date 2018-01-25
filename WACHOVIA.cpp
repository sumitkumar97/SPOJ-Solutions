#include <iostream>
#include <cstdio>
using namespace std ;

int test , k , m , w[60] , v[60] , dp[210][10010] ;

int rec ( int iter , int filled ){
  if ( iter >= m || filled >= k )
    return 0 ;
  if ( dp[iter][filled] != -1 )
    return dp[iter][filled] ;
  return dp[iter][filled] = max ( rec ( iter + 1 , filled ) , (filled + w[iter] <= k )? v[iter] + rec ( iter + 1 , filled + w[iter] ) : 0 ) ;
}

int main() {

  scanf("%d" , &test ) ;
  while ( test -- ){
    for ( int i = 0 ; i < 210 ; i ++ )
      for ( int j = 0 ; j < 10010 ; j ++ )
	dp[i][j] = -1 ;
    scanf("%d%d" , &k , &m ) ;
    for ( int i = 0 ; i < m ; i ++ )
      scanf("%d%d" , &w[i] , &v[i] ) ;
    printf("Hey stupid robber, you can get %d.\n" , rec ( 0 , 0 ) ) ;
  }
  return 0 ;
}
