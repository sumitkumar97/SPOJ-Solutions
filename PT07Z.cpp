#include <iostream>
#include <cstdio>
using namespace std ;

int noofnodes ;
bool adjmatrix[10010][10010] = {false} ;
bool visited[10010] = {false} ;
int count = -1 , finalcount = 0 , desirednode ;
void dfs ( int node ) {
  count ++ ;
  for ( int i = 1 ; i <= noofnodes ; i ++ ) {
    if ( adjmatrix[node][i] && !visited[i] ) {
      visited[i] = true ;
      dfs( i ) ;
    }
    if ( count > finalcount ) {
      finalcount = count ;
      desirednode = node ;
    }
  }
  count -- ;
}

int main() {
  scanf("%d",&noofnodes) ;
  int u , v ;
  for ( int k = 0 ; k < noofnodes - 1 ; k ++ ) {
    scanf("%d%d",&u,&v) ;
    adjmatrix[u][v] = true ;
    adjmatrix[v][u] = true ;
  }
  visited[1] = true ;
  dfs(1) ;
  count = -1 ;
  finalcount = 0 ;
  for ( int i = 0 ; i < 10010 ; i ++ )
    visited[i] = false ;
  visited[desirednode] = true ;
  dfs(desirednode) ;
  printf("%d",finalcount) ;
  return 0 ;
}



  
