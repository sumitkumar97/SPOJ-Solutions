#include <iostream>
#include <cstdio>
#include <vector>
using namespace std ;

int lca ( int v , int w , int* parent ){
  vector<int> vpath , wpath ;
  while ( v ){
    vpath.push_back ( v ) ;
    v = parent[v] ;
  }
  while ( w ){
    wpath.push_back ( w ) ;
    w = parent[w] ;
  }
  int i = vpath.size() - 1 , j = wpath.size() - 1 ;
  while ( i >= 0 && j >= 0 ){
    if ( vpath[i] != wpath[j] )
      break ;
    i -- ;
    j -- ;
  }
  return vpath[i+1] ;
}

int main() {
  int test , n , m , temp , v , w , q ;
  scanf("%d" , &test ) ;
  for ( int k = 1 ; k <= test ; k ++ ){
    int parent[1010] = {0} ;
    scanf("%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i ++ ){
      scanf("%d" , &m ) ;
      while ( m -- ){
	scanf("%d" , &temp ) ;
	parent[temp] = i ;
      }
    }
    printf("Case %d:\n" , k ) ;
    scanf("%d" , &q ) ;
    while ( q -- ){
      scanf("%d%d" , &v , &w ) ;
      printf("%d\n" , lca ( v , w , parent ) ) ;
    }
  }
  return 0 ;
}
