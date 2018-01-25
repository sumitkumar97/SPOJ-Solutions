#include <iostream>
#include <cstdio>
using namespace std ;

int n , dp[300] ;
char arr[300] ;

int rec ( int left ){
  if ( left >= n )
    return dp[left] = 0 ;
  if ( dp[left] != -1 )
    return dp[left] ;
  int sour = 0 , sweet = 0 , maxi = -1 ;
  for ( int i = left ; i < n ; i ++ ){
    if ( arr[i] == '0' )
      sour ++ ;
    else
      sweet ++ ;
    int next = rec ( i + 1 ) , ans ;
    if ( sweet > sour ) 
      ans = sweet + sour + next ;
    else
      ans = next ;
    if ( ans > maxi )
      maxi = ans ;
  }
  return dp[left] = maxi ;
}

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    scanf("%s" , arr ) ;
    for ( int i = 0 ; i <= n ; i ++ )
      dp[i] = -1 ;
    printf("%d\n" , rec ( 0 ) ) ;
  }
  return 0 ;
}
