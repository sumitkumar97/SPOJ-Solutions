#include <iostream>
#include <cstdio>
using namespace std ;

int n , block[40][5] , dp[3000][3000] ;

int rec ( int len , int bre , int hei ){
  int maxi = 0 ;
  if  ( dp[len][bre] != -1 )
    return dp[len][bre] + hei ;
  for ( int i = 0 ; i < n ; i ++ )
    for ( int j = 0 ; j < 3 ; j ++ )
      for ( int k = 0 ; k < 3 ; k ++ )
	for ( int l =  0 ; l < 3 ; l ++ ){
	  if ( j != k && k != l && l != j ){
	    if ( block[i][j] < len && block[i][k] < bre )
	      if ( rec ( block[i][j] , block[i][k] , block[i][l] ) > maxi )
		maxi = rec ( block[i][j] , block[i][k] , block[i][l] ) ;
	  }
	}
  dp[len][bre] = maxi ;
  return hei + maxi ;
}
  
  

int main() {
  scanf("%d" , &n ) ;
  while ( n ){

    for ( int i = 0 ; i <= 2501 ; i ++ )
      for ( int j = 0 ; j <= 2501 ; j ++ )
	dp[i][j] = -1 ;
    
    for ( int i = 0 ; i < n ; i ++ )
      for ( int j = 0 ; j < 3 ; j ++ )
	scanf("%d" , &block[i][j] ) ;
    printf("%d\n" , rec ( 2501 , 2501 , 0 ) ) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
