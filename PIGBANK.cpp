#include <iostream>
#include <cstdio>
using namespace std ;

int e , f , desired_weight , n , p[510] , w[510] , dp[510][10010] ;

int rec ( int coin , int weight ){
  if ( dp[coin][weight] != -1 )
    return dp[coin][weight] ;
  if ( coin < n ){
    if ( weight >= w[coin] )
      return dp[coin][weight] = min ( p[coin] + min ( rec ( coin , weight - w[coin] ) , rec ( coin + 1 , weight - w[coin] ) ) , rec ( coin + 1 , weight ) ) ;
    else
      return dp[coin][weight] = rec ( coin + 1 , weight ) ;
  }
  if ( weight == 0 )
    return dp[coin][weight] = -7000000 ;
  return dp[coin][weight] = 1000000000 ;
}


int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test -- ) {
    scanf("%d%d",&e,&f) ;
    for ( int i = 0 ; i < 510 ; i ++ )
      for ( int j = 0 ; j < 10010 ; j ++ )
	dp[i][j] = - 1;
    desired_weight = f - e ;
    scanf("%d",&n) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d%d",&p[i] , &w[i] ) ;
    int ans = rec ( 0 , desired_weight ) ;
    if ( ans < 0 )
      printf("The minimum amount of money in the piggy-bank is %d.\n",ans+7000000) ;
    else
      printf("This is impossible.\n") ;
  }
  return 0 ;
}
    
