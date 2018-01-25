#include <iostream>
#include <cstdio>
#define MAX 2000000000
using namespace std ;

int n , arr[110] , dp[110][110] ;

int rec ( int l , int r , int total ){
  if ( l == r )
    return 0 ;
  if ( dp[l][r] != -1 )
    return dp[l][r] ;
  int ans = MAX, sumfirst = 0 ;

  for ( int divider = l ; divider < r ; divider ++ ){

    sumfirst += arr[divider] ;

    ans = min ( ans , rec ( l , divider , sumfirst ) + rec ( divider + 1 , r , total - sumfirst ) + ( (sumfirst%100)*( ( total-sumfirst )%100 ) ) ) ; // (N-1)th mixing for first call
  }
  return dp[l][r] = ans ;
}

int main() {

  while ( scanf("%d" , &n ) != EOF ){

    for ( int i = 0 ; i < n ; i ++ )
      for ( int j = 0 ;  j < n ; j ++ )
	dp[i][j] = -1 ;

    int temp = 0 ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d" , &arr[i] ) ;
      temp += arr[i] ;
    }
    printf("%d\n" , rec ( 0 , n - 1 , temp ) ) ;
  }
  return 0 ;
}
