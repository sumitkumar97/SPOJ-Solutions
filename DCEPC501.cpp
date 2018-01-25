#include <iostream>
#include <cstdio>
using namespace std ;

typedef long long ll ;

int n , arr[100010] ;
ll dp[100010][4] ;

ll rec ( int iter , int no ){

  ll ans = 0 ;
  
  if ( iter >= n )
    return 0 ;

  if ( dp[iter][no] != -1 )
    return dp[iter][no] ;
  
  for ( int i = 0 ; i + iter < n && i < no ; i ++ ){
    ans += arr[iter+i] ;
  }

  ans += max ( max ( rec ( iter + (no<<1) , 1 ) ,rec ( iter + (no<<1) , 2 ) ), rec ( iter + (no<<1) , 3 ) ) ;

  return dp[iter][no] = ans ;
}

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i ++)
      for ( int j = 1 ; j < 4 ; j ++ )
	dp[i][j] = -1 ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &arr[i] ) ;
    printf("%lld\n" , max ( max ( rec ( 0 , 1 ) , rec ( 0 , 2 ) ) , rec ( 0 , 3 ) ) ) ;
  }
  return 0 ;
}
