#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std ;

struct trie {
  int words ;
  trie *edge[10] ;
} ;

trie* create_node() {
  trie *p ;
  p = (trie*) malloc ( sizeof (trie) ) ;
  return p ;
}

void initialize(trie &a) {
  a.words = 0 ;
  for ( int i = 0 ; i < 10 ; i ++ )
    a.edge[i] = NULL ;
}

void addword ( trie &vertex , char *word , int l , int r ) {
  if ( l > r ) {
    vertex.words ++ ;
  }
  else {
    int a = (int) word[l] - 48 ;
    if ( vertex.edge[a] == NULL ) {
      vertex.edge[a] = create_node() ;
      initialize(*vertex.edge[a]) ;
    }
    addword ( *vertex.edge[a] , word , l+1 , r );
  }
}

int countprefix ( trie &vertex , char *check , int l , int r ) {
  if ( l > r ) {
    if ( vertex.words > 1 )
      return 1 ;
    for ( int i = 0 ; i < 10 ; i ++ ) {
      if ( vertex.edge[i] != NULL )
	return 1 ;
    }
    return 0 ;
  }
  if ( vertex.words > 0 ) {
    return 1 ;
  }
  int a = (int) check[l] - 48 ;
  countprefix( *vertex.edge[a] , check , l+1 , r) ;
}

int main() {
  int test , n , i ;
  scanf("%d",&test) ;
  char a[10010][12] ;
  while ( test -- ) {
    trie *root = create_node() ;
    initialize ( *root ) ;
    scanf("%d",&n) ;
    for ( i = 0 ; i < n ; i ++ ) {
      scanf("%s",a[i]) ;
      addword ( *root , a[i] , 0 , strlen(a[i])-1 ) ;
    }
    bool flag = true ;
    for ( i = 0 ; i < n ; i ++ ) {
      if ( countprefix ( *root , a[i] ,0, strlen(a[i])-1 ) ) {
	flag = false ;
	break ;
      }
    }
    if ( flag )
      printf("YES\n") ;
    else
      printf("NO\n") ;
  }
  return 0 ;
}
