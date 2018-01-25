#include <iostream>
#include <cstdio>
#define MAX 2e9 ;
using namespace std ;

int n , seg[400010] , ia[100010] ;

void seg_build ( int vertex , int lseg , int rseg ){

  if ( lseg == rseg ){
    seg[vertex] = ia[lseg] ;
    return ;
  }
  int mid = ( lseg + rseg)>>1 ;
  seg_build ( vertex<<1 , lseg , mid ) ;
  seg_build ( (vertex<<1) + 1 , mid + 1 , rseg ) ;

  seg[vertex] = min ( seg[vertex<<1] , seg[(vertex<<1)+1] );
}

int query ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( rquery < lseg || lquery > rseg )
    return MAX ;

  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex] ;
  
  int mid = (lseg + rseg)>>1 , lchild = vertex<<1 ;
  
  return min ( query ( lchild , lseg , mid , lquery , rquery ) , query ( lchild + 1 , mid + 1 , rseg , lquery , rquery ) ) ;
}

int main() {
  int test , q , a , b ;
  scanf("%d" , &test ) ;
  int scenario = 1 ;
  while ( test -- ){
    scanf("%d%d" , &n , &q ) ;
    printf("Scenario #%d:\n" , scenario ) ;

    for ( int i = 1 ; i <= n ; i ++ )
      scanf("%d" , &ia[i] ) ;

    seg_build ( 1 , 1 , n ) ;

    while ( q -- ){
      scanf("%d%d" , &a , &b ) ;
      printf("%d\n" , query ( 1 , 1 , n , a , b ) ) ;
    }
    scenario ++ ;
  }
  return 0 ;
}
