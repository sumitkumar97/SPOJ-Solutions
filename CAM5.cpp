#include <iostream>
#include <cstdio>
#include <vector>
using namespace std ;

vector<int> adjlist[100010] ;
bool visited[100010] ;

void dfs ( int v ){
  visited[v] = true ;
  for ( int i = 0 ; i < adjlist[v].size() ; i ++ )
    if ( !visited[ adjlist[v][i] ] )
      dfs ( adjlist[v][i] ) ;
}

int main() {
  int test , n , e , a , b ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ ){
      adjlist[i].clear() ;
      visited[i] = false ;
    }
    scanf("%d" , &e ) ;
    for ( int i = 0 ; i < e ; i ++ ){
      scanf("%d%d" , &a , &b ) ;
      adjlist[a].push_back(b) ;
      adjlist[b].push_back(a) ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
      if ( !visited[i] ){
	ans ++ ;
	dfs(i) ;
      }
    printf("%d\n" , ans ) ;
  }
  return 0 ;
}
