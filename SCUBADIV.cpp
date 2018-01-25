#include <iostream>
#include <cstdio>
using namespace std ;

int test , reqo , reqn , containers , weight[1010] , oxy[1010] , nitro[1010] , MAX = 1000000000 , dp[1001][22][80] ;

int rec ( int c , int o , int n ){
  if ( dp[c][o][n] != -1 )
    return dp[c][o][n] ;
  if ( o == 0 && n == 0 )
    dp[c][o][n] = 0 ;
  else if ( c == containers )
    dp[c][o][n] = MAX ;
  else
    dp[c][o][n] = min ( rec ( c + 1 , o , n ) , weight[c] + rec ( c + 1 , max ( 0 , o - oxy[c] ) , max ( 0 ,  n - nitro[c] ) ) ) ;
  return dp[c][o][n] ;
}

int main() {
  scanf("%d" , &test ) ;
  while ( test -- ){
    for ( int i = 0 ; i < 1001 ; i ++ )
      for ( int j = 0 ; j < 22 ; j ++ )
	for ( int k = 0 ; k < 80 ; k ++ )
	  dp[i][j][k] = -1 ;
    scanf("%d%d" , &reqo , &reqn ) ;
    scanf("%d" , &containers ) ;
    for ( int i = 0 ; i < containers ; i ++ )
      scanf("%d%d%d" , &oxy[i] , &nitro[i] , &weight[i] ) ;
    int ans = rec ( 0 , reqo , reqn ) ;
    printf("%d\n",ans) ;
  }
  return 0 ;
}
