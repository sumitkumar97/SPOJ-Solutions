#include <iostream>
#include <cstdio>
using namespace std ;

int n , lazy[400010] ;

struct seg_struct {
  int arr[3] ;
}seg[400010] ;

void seg_build ( int vertex , int lseg , int rseg ){
  if ( lseg == rseg ){
    seg[vertex].arr[0] = 1 ;
    seg[vertex].arr[1] = 0 ;
    seg[vertex].arr[2] = 0 ;
    return ;
  }
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  seg_build ( lchild , lseg , mid ) ;
  seg_build ( lchild + 1 , mid + 1 , rseg ) ;

  for ( int i = 0 ; i < 3 ; i ++ )
    seg[vertex].arr[i] = seg[lchild].arr[i] + seg[lchild+1].arr[i] ;
}

void update ( int vertex , int lseg , int rseg , int lquery , int rquery ){


  if ( lazy[vertex] ){
    int temp[3] ;
    temp[0] = seg[vertex].arr[0] ;
    temp[1] = seg[vertex].arr[1] ;
    temp[2] = seg[vertex].arr[2] ;
    seg[vertex].arr[lazy[vertex]%3] = temp[0] ;
    seg[vertex].arr[ (1 + lazy[vertex]) %3] = temp[1] ;
    seg[vertex].arr[ (2 + lazy[vertex]) %3] = temp[2] ;

    if ( lseg != rseg ){
      lazy[vertex<<1] += lazy[vertex] ;
      lazy[(vertex<<1)+1] += lazy[vertex] ;
    }

    lazy[vertex] = 0 ;
  }
  if ( lquery > rseg || rquery < lseg )
    return ;

  
  if ( lseg >= lquery && rseg <= rquery ){
    int temp ;
    temp = seg[vertex].arr[2] ;
    seg[vertex].arr[2] = seg[vertex].arr[1] ;
    seg[vertex].arr[1] = seg[vertex].arr[0] ;
    seg[vertex].arr[0] = temp ;
    
    if ( lseg != rseg ){
      lazy[vertex<<1] += 1 ;
      lazy[(vertex<<1)+1] += 1 ;
    }
    return ;
  }
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  update ( lchild , lseg , mid , lquery , rquery ) ;
  update ( lchild + 1 , mid + 1 , rseg , lquery , rquery ) ;

  for ( int i = 0 ; i < 3 ; i ++ )
    seg[vertex].arr[i] = seg[lchild].arr[i] + seg[lchild +1].arr[i] ;
}

int query ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( lquery > rseg || rquery < lseg )
    return 0 ;
  if ( lazy[vertex] ){
    int temp[3] ;
    temp[0] = seg[vertex].arr[0] ;
    temp[1] = seg[vertex].arr[1] ;
    temp[2] = seg[vertex].arr[2] ;
    seg[vertex].arr[lazy[vertex]%3] = temp[0] ;
    seg[vertex].arr[ (1 + lazy[vertex]) %3] = temp[1] ;
    seg[vertex].arr[ (2 + lazy[vertex]) %3] = temp[2] ;

    if ( lseg != rseg ){
      lazy[vertex<<1] += lazy[vertex] ;
      lazy[(vertex<<1)+1] += lazy[vertex] ;
    }

    lazy[vertex] = 0 ;
  }
      
  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex].arr[0] ;
  
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  return query ( lchild , lseg , mid , lquery , rquery ) + query ( lchild + 1 , mid + 1 , rseg , lquery , rquery ) ;
}

int main() {
  int q , a , b , qtype ;
  scanf("%d%d" , &n , &q ) ;

  seg_build ( 1 , 0 , n - 1 ) ;
  
  while ( q -- ){
    scanf("%d%d%d" , &qtype , &a , &b ) ;
    if ( qtype )
      printf("%d\n" , query( 1 , 0 , n-1 , a , b ) ) ;
    else
      update ( 1 , 0 , n-1 , a , b ) ;
  }
  return 0 ;
}
