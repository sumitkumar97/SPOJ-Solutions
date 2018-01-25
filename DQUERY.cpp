#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std ;

int coun[1000010] , inputarray[30010] , block , n , no_of_queries ;

struct query {
  int l , r , position ;
} q[200010] ;

bool compare ( query x , query y ) {
  if (x.l/block != y.l/block)
    return x.l/block < y.l/block;
  return x.r < y.r ;
}

int sol[200010] ;

void query_solving( ) {
  block = (int)sqrt(n);
  sort(q, q + no_of_queries , compare);
  int currL = 1 , currR = 1 ;
  int currunique = 1 ;
  coun[inputarray[1]] = 1 ;
  for (int i = 0; i < no_of_queries ; i++) {
    int L = q[i].l , R = q[i].r ;
    while ( currL < L ) {
      coun[inputarray[currL]] -- ;
      if ( coun[inputarray[currL]] == 0 )
	currunique -- ;
      currL ++ ;
    }
    while ( currL > L ) {
      currL -- ;
      coun[inputarray[currL]] ++ ;
      if ( coun[inputarray[currL]] == 1 ) {
	currunique ++ ;
      }
    }
    while ( currR < R ) {
      currR ++ ;
      coun[inputarray[currR]] ++ ;
      if ( coun[inputarray[currR]] == 1 ){
	currunique ++ ;
      }
    }
    while ( currR > R ) {
      coun[inputarray[currR]] -- ;
      if ( coun[inputarray[currR]] == 0 )
	currunique -- ;
      currR -- ;
    }
    sol[q[i].position] = currunique ;
  }
}

int main() {
  scanf("%d",&n) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    scanf("%d",&inputarray[i]) ;
  }
  scanf("%d",&no_of_queries) ;
  for ( int i = 0 ; i < no_of_queries ; i ++ ) {
    scanf("%d%d", &q[i].l , &q[i].r ) ;
    q[i].position = i ;
  }
  query_solving() ;
  for ( int i = 0 ; i < no_of_queries ; i ++ ) {
    printf("%d\n" , sol[i] ) ;
  }
  return 0 ;
}

  
