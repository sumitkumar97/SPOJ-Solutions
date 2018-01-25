#include <iostream>
#include <cstdio>
using namespace std ;

int seg[500000] ,  inputarray[100010] ;

void build_seg( int vertex , int left , int right ){
  if ( left == right )
    seg[vertex] = left ;
  else {
    build_seg ( vertex<<1 , left , (left+right)>>1 ) ;
    build_seg ( (vertex<<1) + 1 , (left+right>>1) + 1 , right) ;
    seg[vertex] = inputarray[seg[vertex<<1]] > inputarray[seg[(vertex<<1) + 1]] ? seg[vertex<<1] : seg[(vertex<<1) + 1] ;
  }
}

int query ( int vertex , int lseg , int rseg , int lquery , int rquery ) {
  if ( lquery > rseg || rquery < lseg )
    return -1 ;
  if ( lquery <= lseg && rquery >= rseg )
    return seg[vertex] ;
  int leftchild , rightchild ;
  leftchild = query ( vertex<<1 , lseg , (lseg + rseg)>>1 , lquery , rquery ) ;
  rightchild = query ( (vertex<<1) + 1 , ((lseg+rseg)>>1) + 1 , rseg , lquery , rquery) ;
  if ( leftchild < 0 )
    return rightchild ;
  if ( rightchild < 0 )
    return leftchild ;
  return ( inputarray[leftchild] > inputarray[rightchild] ) ? leftchild : rightchild ;
}

void update ( int vertex , int lseg , int rseg , int indextobeupdated , int value ) {
  if ( !( lseg <= indextobeupdated && indextobeupdated <= rseg ) )
    return ;
  if ( rseg == lseg && rseg == indextobeupdated )
    seg[vertex] = indextobeupdated ;
  else {
    update ( vertex<<1 , lseg , ( lseg+rseg)>>1 , indextobeupdated , value ) ;
    update ( (vertex<<1) + 1 , (lseg + rseg>>1) + 1 , rseg  , indextobeupdated , value ) ;
    seg[vertex] = inputarray[seg[vertex<<1]] > inputarray[seg[(vertex<<1) + 1]] ? seg[vertex<<1] : seg[(vertex<<1) + 1] ;
  }
}


int main() {
  int n , noofqueries , x , y , i , largest , secondlargest , temp ;
  char querytype ;
  scanf("%d",&n) ;
  for ( int  i = 1  ; i <= n ;i ++ )
    scanf("%d",&inputarray[i]) ;
  scanf("%d",&noofqueries) ;
  build_seg ( 1 , 1, n ) ;
  for ( int j = 0 ; j < noofqueries ; j++) {
    scanf("%c",&querytype) ;
    scanf("%c",&querytype) ;
    if ( querytype == 'U' ) {
      scanf("%d%d",&i,&x) ;
      inputarray[i] = x ;
      update ( 1 , 1 , n , i , x ) ;
    }
    else {
      scanf("%d%d",&x , &y) ;
      if ( x == y )
	printf("%d\n",inputarray[x]) ;
      else {
	largest = query ( 1 , 1 , n , x , y ) ;
	temp = inputarray[largest] ;
	inputarray[largest] = -1 ;
	update ( 1 , 1 , n , largest , -1 ) ;
	secondlargest = query ( 1 , 1 , n , x , y ) ;
	inputarray[largest] = temp ;
	update ( 1 , 1 , n , largest , temp ) ;
	printf("%d\n",temp + inputarray[secondlargest] ) ;
      }
    }
  }
  return 0 ;
}






  
