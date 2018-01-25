#include <iostream>
#include <cstdio>
using namespace std ;

int n, k , arr[110] , dp[110][110][110] ; 

int rec ( int cases , int iter , int weight ){
  if ( weight == k )
    return 0 ;
  if ( weight > k || cases >= n || iter > k )
    return 100010 ;
  if ( dp[cases][iter][weight] != -1 )
    return dp[cases][iter][weight] ;
  if ( arr[iter] == -1 )
    return dp[cases][iter][weight] = rec ( cases , iter + 1 , weight ) ;
  return dp[cases][iter][weight] = min ( min ( rec ( cases + 1 , iter , weight + iter ) , rec ( cases + 1 , iter + 1 , weight + iter ) ) + arr[iter]  , rec ( cases , iter + 1 , weight ) ) ;
}

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    for ( int i = 0 ; i < 110 ; i ++ )
      for ( int j = 0 ; j < 110 ; j ++ )
	for ( int k = 0 ; k < 110 ; k ++ )
	  dp[i][j][k] = -1 ;
    scanf("%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= k ; i ++ )
      scanf("%d" , &arr[i] ) ;
    int ans =  rec ( 0 , 1 , 0 ) ;
    if ( ans >= 100010 )
      printf("-1\n") ;
    else
      printf ( "%d\n" , ans ) ;
  }
  return 0 ;
}
  
  
  
