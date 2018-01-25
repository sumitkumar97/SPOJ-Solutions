#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

char s[30] ;
int n ;
int dp[30][250][250] ;

int cut_after ( int iter , int lsum , int rsum ){
  if ( iter >= n - 1 )
    return 1 ;
  if ( dp[iter][lsum][rsum] != -1 )
    return dp[iter][lsum][rsum] ;
  int ans = cut_after ( iter + 1 , lsum + s[iter+1] - '0' , rsum - s[iter+1] + '0' ) ; // cut has not been made
  if ( lsum <= rsum ){
    int temp = 0 , i = iter ;
    while ( temp < lsum && i + 1 < n ){ 
      i ++ ;
      temp += s[i] - '0' ;
    }
    if ( temp == 0 ){
      temp += s[ iter + 1 ] - '0' ;
      i ++ ;
    }
    ans += cut_after ( i , temp , rsum - temp ) ;
  }
  return dp[iter][lsum][rsum] = ans ;
}


int main() {
  int test = 0 , sum ;
  scanf("%s" , s ) ;
  while ( s[0] != 'b' ){
    for ( int i = 0 ; i < 30 ; i ++ )
      for ( int j = 0 ; j < 250 ; j ++ )
	for ( int k = 0 ; k < 250 ; k ++ )
	  dp[i][j][k] = -1 ;
    test ++ ;
    int sum = 0 ;
    n = strlen(s) ;
    for ( int i = 0 ; i < n ; i ++ )
      sum += s[i] - '0' ;
    int ans = cut_after ( 0 , s[0]-'0' , sum - s[0] + '0' ) ;
    printf("%d. %d\n" , test , ans ) ;
    scanf("%s" , s ) ;
  }
  return 0 ;
}
    
