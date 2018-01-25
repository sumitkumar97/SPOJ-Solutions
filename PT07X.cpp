#include <iostream>
#include <cstdio>
#include <vector>
using namespace std ;

int n , u , v , dp[100010][2] ;
vector<int> adjlist[100010] ;

int rec ( int vertex , int prev , int parent ){
  int ans = 0 ;
  if ( dp[vertex][prev] != -1 )
    return dp[vertex][prev] ;
  if ( prev ){
    for ( int i = 0 ; i < adjlist[vertex].size() ; i ++ )
      if ( adjlist[vertex][i] != parent )
	ans += rec ( adjlist[vertex][i] , 0 , vertex ) ;
  }
  else {
    ans = 1 ;
    for ( int i = 0 ; i < adjlist[vertex].size() ; i ++ )
      if ( adjlist[vertex][i] != parent )
	ans += min ( rec ( adjlist[vertex][i] , 1 , vertex ) , rec ( adjlist[vertex][i] , 0 , vertex ) ) ;
  }
  return dp[vertex][prev] = ans ;
}

int main(){
  scanf("%d" , &n ) ;
  for ( int i = 1 ; i <= n ; i++ )
    for ( int j = 0 ; j < 2 ; j ++ )
      dp[i][j] = -1 ;
  for ( int i = 0 ; i < n - 1 ; i ++ ){
    scanf("%d%d" , &u , &v ) ;
    adjlist[u].push_back(v) ;
    adjlist[v].push_back(u) ;
  }
  if ( n == 1 )
    printf("1\n") ;
  else
    printf("%d\n" , min ( rec(1 , 0 , 0 ) , rec ( 1 , 1 , 0 ) )) ;
  return 0 ;
}
