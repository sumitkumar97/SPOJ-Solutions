#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int len ;
char arr[5010] ;
bool valid ;

long long dp[5010] ;

long long rec ( int curr ){
  if ( dp[curr] != -1 )
    return dp[curr] ;
  if ( curr > len - 1 )
    return dp[curr] = 0 ;
  if ( arr[curr] == '0' ){
    valid = false ;
    return dp[curr] = 0 ;
  }
  if ( curr <= len - 2){
    if ( arr[curr + 1] == '0' ){
      if ( ! ( arr[curr] == '1' || arr[curr] == '2' )){
	valid = false ;
	return dp[curr] = 0 ;
      }
      return dp[curr] = rec ( curr + 2 ) ;
    }
  }
  if ( curr <= len - 3 ){
    if ( arr[curr + 2] == '0' ){
      if ( arr[curr + 1] != '1' && arr[curr + 1] != '2' ){
	valid = false ;
	return dp[curr] = 0 ;
      }
      return dp[curr] = rec ( curr + 3 ) ;
    }
  }
  if ( curr <= len - 2 ){
    if ( ( arr[curr] == '1' && arr[curr+1] <= '9') || ( arr[curr] == '2' && arr[curr+1] <= '6' ) )
	 return dp[curr] = 1 + rec ( curr + 1 ) + rec ( curr + 2 ) ;
  }
  return dp[curr] = rec ( curr + 1 ) ;
}

int main(){
  scanf("%s",arr) ;
  while ( arr[0] != '0' ){
    long long ans ;
    len = strlen ( arr ) ;
    valid = true ;
    for ( int i = 0 ; i < 5010 ; i ++ )
      dp[i] = -1 ;
    ans = rec (0) + 1 ;
    if ( valid )
      printf("%lld\n",ans) ;
    else
      printf("0\n") ;
    scanf("%s",arr) ;
  }
  return 0 ;
}
