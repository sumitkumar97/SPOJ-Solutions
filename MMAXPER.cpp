#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int n , a[1010] , b[1010] , dp[1010][1010] ;

int rec ( int iter , int prevh ){
  if ( iter == n )
    return 0 ;
  if ( dp[iter][prevh] != -1 )
    return dp[iter][prevh] ;
  return dp[iter][prevh] = max ( ((iter>0)? abs ( a[iter] - prevh ):0) + b[iter] + rec ( iter + 1 , a[iter] ) , ((iter>0)?abs ( b[iter] - prevh ):0) + a[iter] + rec ( iter + 1 , b[iter] ) ) ;
}
	       

int main() {
  scanf("%d" , &n ) ;
  for ( int i = 0 ; i < 1010 ; i ++ )
    for ( int j = 0 ; j < 1010 ; j ++ )
      dp[i][j] = -1 ;
  for ( int i = 0 ;i < n ; i ++ )
    scanf("%d%d" , &a[i] , &b[i] ) ;
  printf("%d\n" , rec ( 0 , 0 ) ) ;
  return 0 ;
}
