#include <iostream>
#include <cstdio>
using namespace std ;

int seg[400010] ;

bool lazy[400010] ;

void update ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( lazy[vertex] ){
    seg[vertex] = (rseg - lseg + 1 ) - seg[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex << 1] = !lazy[vertex<<1] ;//
      lazy[(vertex<<1) + 1] = !lazy[(vertex<<1)+1] ;//
    }
    lazy[vertex] = false ;
  }
  if ( lquery > rseg || rquery < lseg )
    return ;
  if ( lseg >= lquery && rseg <= rquery ){
    seg[vertex] = (rseg-lseg+1) - seg[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex << 1] = !lazy[vertex<<1] ;//
      lazy[(vertex<<1) + 1] = !lazy[(vertex<<1)+1] ;//
    }
    return ;
  }
  update ( (vertex<<1) , lseg , (lseg+rseg)>>1 , lquery , rquery ) ;
  update ( (vertex<<1) + 1 , ((lseg+rseg)>>1)+1 , rseg , lquery , rquery ) ;
  seg[vertex] = seg[vertex<<1] + seg[(vertex<<1)+1] ;
}


int query ( int vertex , int lseg , int rseg , int lquery , int rquery ) {
  if ( rseg < lquery || lseg > rquery )
    return 0 ;
  if ( lazy[vertex] ){
    seg[vertex] = (rseg - lseg + 1 ) - seg[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex << 1] = !lazy[vertex << 1] ;//
      lazy[(vertex<<1) + 1] = !lazy[(vertex<<1) + 1] ;// the lazy[children] must be set respective to their previous lazy state 
    }
    lazy[vertex] = false ;
  }
  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex] ;
  return query ( (vertex<<1) , lseg , (lseg+rseg)>>1 , lquery , rquery ) + query ( (vertex<<1)+1 , ((lseg+rseg)>>1)+1 , rseg , lquery , rquery ) ;
}

int main() {
  int n , m , o , s , e ;
  scanf("%d%d" , &n , &m ) ;
  for ( int i = 0 ; i < m ; i ++ ){
    scanf("%d%d%d" , &o , &s , &e ) ;
    if ( !o )
      update ( 1 , 1 , n , s , e ) ;
    else 
      printf("%d\n" , query ( 1 , 1 , n , s , e ) ) ;
  }
  return 0 ;
}
  
