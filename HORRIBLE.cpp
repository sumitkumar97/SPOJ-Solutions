#include <iostream>
#include <cstring>
using namespace std ;

long long seg[900010] , lazy[900010] ;

void update ( int vertex,  int lrange, int rrange, int x, int y , long long value){
  if(lazy[vertex] > 0 ){
    seg[vertex] += ( rrange - lrange + 1 ) * lazy[vertex] ;
    if ( lrange != rrange) {
      lazy[vertex*2] += lazy[vertex] ;
      lazy[vertex*2 + 1] += lazy[vertex] ;
    }
    lazy[vertex] = 0 ;
  }

  if ( x > rrange || y < lrange)
    return ;
  if ( x <= lrange && y >= rrange){
    seg[vertex] += ( rrange - lrange + 1 ) * value ;
    if ( lrange != rrange ) {
      lazy[vertex*2] += value ;
      lazy[vertex*2 + 1] += value ;
    }
    lazy[vertex] = 0 ;
    return ;
  }
  update ( vertex*2 , lrange , (lrange+rrange)/2 , x , y , value ) ;
  update ( vertex*2 + 1 , (lrange+rrange)/2+1 , rrange , x , y , value ) ;
  seg[vertex] = seg[vertex*2] + seg[vertex*2 + 1 ] ;
}


long long query ( int vertex , int lrange , int rrange , int x , int y ) {
  if ( x > rrange || y < lrange ) {
    return 0 ;
  }
  if ( lazy[vertex] > 0 ) {
    seg[vertex] += ( rrange - lrange + 1 )*lazy[vertex] ;
    if ( lrange != rrange ) {
      lazy[vertex*2] += lazy[vertex] ;
      lazy[vertex*2 + 1] += lazy[vertex] ;
    }
    lazy[vertex] = 0 ;
  }
  if ( x <= lrange && y >= rrange ) {
    return seg[vertex] ;
  }
  return query ( vertex*2 , lrange , (lrange+rrange)/2 , x , y ) + query ( vertex*2 + 1 , (lrange+rrange)/2 +1 , rrange , x , y ) ;
}



int main() {
  int test , n , c , query_type , p , i , q ;
  cin>>test ;
  long long v ;
  while ( test -- ) {
    cin >> n >> c ;
    memset ( lazy , 0 ,sizeof(lazy) ) ;
    memset ( seg , 0 , sizeof(seg) ) ;
    for ( i = 0 ; i < c ; i ++ ) {
      cin>>query_type ;
      if ( query_type ) {
	cin>>p>>q;
	if ( p <= q )
	  cout<<query( 1 , 1 , n , p , q )<<"\n" ;
	else
	  cout<<query( 1, 1 , n , q, p )<<"\n" ;
      }
      else {
	cin>>p>>q>>v ;
	if ( p <= q )
	  update ( 1 , 1 , n , p , q , v ) ;
	else
	  update ( 1, 1, n , q ,p , v ) ;
      }
    }
  }
  return 0 ;
}


