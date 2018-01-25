#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

int n ;
vector<ii> adjlist[50010] ;

int dist[50010] ;

void dfs ( int u , int far ) {
  dist[u] = far ;
  for  ( int i = 0 ; i < adjlist[u].size() ; i ++ ){
    if ( dist[ adjlist[u][i].first ] == -1 )
      dfs ( adjlist[u][i].first , far + adjlist[u][i].second ) ;
  }
}

int main() {
  int test , u , v , w , leaf1 , ans ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i ++ )
      adjlist[i].clear() ;
    for ( int i = 0 ; i < n - 1 ; i ++ ){
      scanf("%d%d%d" , &u , &v , &w ) ;
      adjlist[u].push_back ( make_pair ( v , w ) ) ;
      adjlist[v].push_back ( make_pair ( u , w ) ) ;
    }
    leaf1 = 0 ;
    for ( int i = 1 ; i <= n ; i ++ )
      dist[i] = -1 ;
    dfs ( 1 , 0 ) ;
    for ( int i = 1 ; i <= n ; i ++ )
      if  ( dist[i] > dist[leaf1] )
	leaf1 = i ;

    for ( int i = 1 ; i <= n ; i ++ )
      dist[i] = -1 ;
    dfs ( leaf1 , 0 ) ;
    ans = -1 ;
    for ( int i = 1 ; i <= n ; i ++ )
      if  ( dist[i] > ans )
	ans = dist[i] ;
    printf("%d\n" , ans ) ;
  }
  return 0 ;
}
