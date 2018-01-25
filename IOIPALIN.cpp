#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int len , dp[5010][5010] ;
char s[5010] ;

int rec ( int l , int r ){
  if ( l < 0 && r >= len )
    return 0 ;
  if ( l < 0 )
    return len - 1 - r + 1 ;
  if ( r >= len )
    return l + 1 ;

  if ( dp[l][r] != -1 )
    return dp[l][r] ;
  
  if ( s[l] == s[r] )
    return dp[l][r] = rec ( l - 1 , r + 1 ) ;
  return dp[l][r] = 1 + min ( rec ( l , r + 1 ) , rec ( l - 1 , r ) ) ;
}
    
int main() {
  scanf("%d" , &len ) ;
  scanf("%s" , s ) ;

  for ( int i = 0 ; i < 5010 ; i++ )
    for ( int j = 0 ; j < 5010 ; j ++ )
      dp[i][j] = -1 ;
  
  int ans = 10000 , t ;
  for ( int i = 0 ; i < len - 1 ; i ++ ){
    t = min ( rec ( i , i + 1 ) , rec ( i , i ) ) ;
    if ( t < ans )
      ans = t ;
  }
  ans = min ( rec ( len - 1 , len - 1 ) , ans ) ;
  printf("%d\n" , ans ) ;
  return 0 ;
}
  
