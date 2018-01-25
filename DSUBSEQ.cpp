#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std ;

typedef long long ll ;

int main() {
  int test , dp[100010] , n , mod = 1000000007 ;
  char s[100010] ;
  scanf("%d" , &test ) ;
  while ( test -- ) {
    int distinct[100] = {0} ;
    scanf("%s" , s ) ;
    n = strlen(s) ;
    dp[n-1] = 2 ;
    distinct[s[n-1]] = 1 ;
    for ( int i = n - 2 ; i >= 0 ; i -- ){
      ll temp = dp[i+1] ;
      dp[i] = ( ((temp<<1)+mod) - distinct[s[i]] ) % mod ;
      //      printf("%d %d %d \n" , n - i , dp[i] , distinct[s[i]]) ;
      distinct[s[i]] += (dp[i+1] + (mod - distinct[s[i]]))%mod ;
      distinct[s[i]] %= mod ;

    }
    printf("%d\n" , dp[0] ) ;
  }
  return 0 ;
}
