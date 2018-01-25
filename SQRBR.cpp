#include <iostream>
#include <cstdio>
using namespace std ;

int n , k , dp[50][100] ;
bool open[50] ;

int rec ( int iter , int csum ){

  if ( iter > (n<<1) ){
    if ( csum == 0 )
      return 1 ;
    else
      return 0 ;
  }

  if ( dp[iter][csum] != -1 )
    return dp[iter][csum] ;

  int ans = rec ( iter + 1 , csum + 1 ) ;

  if ( csum - 1 >= 0 && !open[iter] )
    ans += rec ( iter + 1 , csum - 1 ) ;

  return dp[iter][csum] = ans ;
}



int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){

    for ( int i = 0 ; i < 50 ; i ++ ){
      open[i] = false ;
      for ( int j = 0 ; j < 100 ; j ++ )
	dp[i][j] = -1 ;
    }

    scanf("%d%d" , &n , &k ) ;

    int temp ;
    for ( int i = 0 ; i < k ; i ++ ){
      scanf("%d" , &temp ) ;
      open[temp] = true ;
    }
    printf("%d\n" , rec ( 1 , 0 ) ) ;
  }
  return 0 ;
}
      
