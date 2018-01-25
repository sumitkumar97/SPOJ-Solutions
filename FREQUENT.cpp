#include <iostream>
#include <cstdio>
using namespace std ;

int n , input_arr[100010] ;

struct segment_tree{
  int maxi , left , leftcount , right , rightcount ;
} seg[400010] ;

void seg_build ( int vertex , int lseg , int rseg ){
  if ( lseg == rseg ){
    seg[vertex].left = seg[vertex].right = input_arr[lseg] ;
    seg[vertex].maxi = seg[vertex].leftcount = seg[vertex].rightcount = 1 ;
    return ;
  }
  int left = (lseg+rseg)>>1 ;
  seg_build ( vertex<<1 , lseg , left ) ;
  seg_build ( (vertex<<1) + 1 , left + 1 , rseg ) ;

  seg[vertex].maxi = max ( seg[vertex<<1].maxi , seg[(vertex<<1) + 1].maxi ) ;
  if ( seg[vertex<<1].right == seg[(vertex<<1) + 1].left && seg[vertex<<1].rightcount + seg[(vertex<<1) + 1].leftcount > seg[vertex].maxi )
    seg[vertex].maxi = seg[vertex<<1].rightcount + seg[(vertex<<1)+1].leftcount ;
  
  seg[vertex].left = input_arr[lseg] ;
  seg[vertex].right = input_arr[rseg] ;

  seg[vertex].leftcount = 0 ;
  int i = lseg ;
  while ( i <= rseg && input_arr[i] == seg[vertex].left ){
    seg[vertex].leftcount ++ ;
    i ++ ;
  }
  i = rseg ;
  seg[vertex].rightcount = 0 ;
  while ( i >= lseg && input_arr[i] == seg[vertex].right ){
    seg[vertex].rightcount ++ ;
    i -- ;
  }
}

int query ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( lquery > rseg || rquery < lseg )
    return -1 ;

  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex].maxi ;

  int left = (lseg+rseg)>>1 ;
  int p1 = query ( vertex<<1 , lseg , left , lquery , rquery ) ;
  int p2 = query ( (vertex<<1) + 1 , left + 1 , rseg , lquery , rquery ) ;
  if ( p1 == -1 )
    return p2 ;
  if ( p2 == -1 )
    return p1 ;

  return max ( max ( p1 , p2 ) , (seg[vertex<<1].right == seg[(vertex<<1) + 1].left) ? ((seg[vertex<<1].rightcount <= (left - lquery + 1) ? seg[vertex<<1].rightcount : (left-lquery+1) ) + ( seg[(vertex<<1)+1].leftcount <= ( rquery - (left+1) + 1 ) ? seg[(vertex<<1) + 1].leftcount : rquery - ( left + 1 ) + 1 )) : -1 ) ;
}

int main() {
  int q ;
  scanf("%d" , &n ) ;
  while ( n ){
    scanf("%d" , &q ) ;

    for ( int i = 1 ; i <= n ; i ++ )
      scanf("%d" , &input_arr[i] ) ;

    seg_build ( 1 , 1 , n ) ;

    int lquery , rquery ;
    for ( int i = 0 ; i < q ; i ++ ){
      scanf("%d%d" , &lquery , &rquery ) ;
      printf("%d\n" , query ( 1 , 1 , n , lquery , rquery ) ) ;
    }
    
    scanf("%d" ,&n ) ;
  }
  return 0 ;
}
