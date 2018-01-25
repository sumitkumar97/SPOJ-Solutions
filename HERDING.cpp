#include <iostream>
#include <cstdio>
using namespace std ;

int n , m ;
char city[1010][1010] ;
int visited[1010][1010] ;
int ans = 0 , stamp = 0 ;

void dfs ( int u , int v  ){
  visited[u][v] = stamp ;
  int pu = u , pv = v ;
  if ( city[u][v] == 'S' )
    u ++ ;
  else if ( city[u][v] == 'E' )
    v ++ ;
  else if ( city[u][v] == 'W' )
    v -- ;
  else if ( city[u][v] == 'N' )
    u -- ;

  //  if ( u >= 0 && v >= 0 && u < n && v < m && !visited[u][v] )
  if ( !visited[u][v] )
    dfs( u , v ) ;
  else if ( visited[u][v] == visited[pu][pv] )
      ans ++ ;
}

int main() {

  scanf("%d%d" , &n , &m ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%s" , city[i] ) ;
  for ( int i = 0 ; i < n ; i ++ )
    for ( int j = 0 ; j < m ; j ++ ){
      if ( !visited[i][j] ){
	stamp ++ ;
	dfs ( i , j ) ;
      }
    }
  printf("%d\n" , ans ) ;
  return 0 ;
}
