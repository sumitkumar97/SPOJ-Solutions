#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , setno , n , k , dp[110][110][2] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d%d%d" , &setno, &n , &k ) ;
    char s[110] ;
    for ( int i = 0 ; i < 110 ; i ++ )
      s[i] = '0' ;
    for ( int i = 0 ; i < 110 ; i ++ )
      for ( int j = 0 ; j < 110 ; j ++ )
	for ( int t = 0 ; t < 2 ; t ++ )
	  dp[i][j][t] = 0 ;
    dp[0][0][0] = 1 ;
    dp[0][0][1] = 1 ;
    dp[1][0][0] = 2 ;
    dp[1][1][1] = 1 ;
    dp[1][0][1] = 1 ; 

    for ( int iter = 2 ; iter < n ; iter ++ ){
      for ( int i = 0 ; i < 101 ; i ++ ){
	dp[iter][i][0] = dp[iter-1][i][0] + dp[iter-1][i][1] ;
	dp[iter][i][1] = dp[iter-1][i][0] ;
	if ( i - 1 >= 0 )
	  dp[iter][i][1] += dp[iter-1][i-1][1] ;
      }
    }
    int ans = 0 ;
    for ( int j = 0 ; j < 2 ; j ++ )
      ans += dp[n-1][k][j] ;
    printf("%d %d\n" , setno , ans ) ;
  }
  return 0 ;
}
