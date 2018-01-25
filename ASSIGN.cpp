#include <iostream>
#include <cstdio>
using namespace std ;

int test , n , arr[30][30] ;
long long dp[1050000] ;

long long rec ( int student , int state ){
  if ( dp[state] != -1 )
    return dp[state] ;
  if ( ( 1 << n ) - 1 == state )
    return dp[state] = 1 ;
  long long ans = 0 ;
  for ( int i = 0 ; i < n ; i ++ ){
    if ( arr[student][i] == 1 && !( state & (1<<n-1-i) ) ){
      int newstate = ( state | ( 1 << n-1-i ) ) ;
      ans += rec ( student + 1 , newstate ) ;
    }
  }
  return dp[state] = ans ;
}

int main(){
  scanf("%d", &test) ;
  while ( test -- ){
    scanf("%d",&n) ;
    for ( int i = 0 ; i < 1050000 ; i ++ )
      dp[i] = -1 ;
    for ( int i = 0 ; i < n ; i ++ )
      for ( int j = 0 ; j < n ; j ++ )
	scanf("%d" , &arr[i][j] ) ;
    printf("%lld\n" , rec ( 0 , 0 )) ;
  }
  return 0 ;
}
