#include <iostream>
#include <cstdio>
using namespace std ;

int n ;

void update ( int vertex , int lseg , int rseg , int *arr , int*seg , int lquery , int rquery , int val ){
  if ( lseg > rquery || rseg < lquery )
    return ;
  if ( lseg >= lquery && rseg <= rquery ){
    seg[vertex] += val ;
    return ;
  }
  update ( vertex<<1 , lseg , (lseg+rseg)>>1 , arr , seg , lquery , rquery , val ) ;
  update ( (vertex<<1) + 1 , ((lseg+rseg)>>1) + 1 , rseg , arr , seg , lquery , rquery , val ) ;
}

int query ( int vertex , int lseg , int rseg , int *arr , int *seg , int index){
  if ( index < lseg || index > rseg )
    return -1 ;
  if ( index == lseg && index == rseg )
    return seg[vertex] ;
  int p1 = query ( vertex<<1 , lseg , (lseg+rseg)>>1 , arr , seg , index );
  int p2 = query ( (vertex<<1)+1 , ((lseg+rseg)>>1) + 1 , rseg , arr , seg , index );
  if ( p1 == -1 )
    return seg[vertex] + p2 ;
  if ( p2 == -1 )
    return seg[vertex] + p1;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test -- ){
    int arr[10010]={0} , seg[40010]={0} , u , l , r , val ;
    scanf("%d%d",&n,&u) ;
    for ( int i = 0 ; i < u ; i++ ){
      scanf("%d%d%d",&l , &r , &val ) ;
      update ( 1 , 0 , n-1 , arr , seg , l , r , val ) ;
    }
    int q , index ;
    scanf("%d",&q) ;
    while ( q -- ){
      scanf("%d",&index ) ;
      printf("%d\n", query ( 1 , 0 , n -1 , arr , seg , index ) ) ;
    }
  }
  return 0;
}
