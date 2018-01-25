#include <iostream>
using namespace std ;

int input_array[1000010] , seg[4000010];

void make_seg ( int vertex , int lsegrange , int rsegrange ) {
  if ( lsegrange == rsegrange ) {
    seg[vertex] =  input_array[lsegrange] ;
  }
  else {
    make_seg ( vertex*2 , lsegrange , (lsegrange + rsegrange)/2 ) ;
    make_seg ( vertex*2 + 1 , (lsegrange + rsegrange)/2 + 1 , rsegrange ) ;
    seg[vertex] = max ( seg[vertex*2] , seg[(vertex * 2) + 1 ] ) ;
  }
}

int query ( int vertex , int lsegrange , int rsegrange , int lquery , int rquery ) {
  if ( lsegrange  > rquery || rsegrange < lquery )
    return -1 ;
  if ( lquery <= lsegrange && rquery >= rsegrange ) {
    return seg[vertex] ;
  }
  int path1 = query ( vertex*2 , lsegrange , (lsegrange + rsegrange)/2 , lquery , rquery ) ;
  int path2 = query ( vertex*2 + 1  , ( lsegrange + rsegrange )/2 + 1  , rsegrange , lquery , rquery ) ;
  if ( path1 == -1 )
    return path2 ;
  if ( path2 == -1 )
    return path1 ;
  return max(path1 , path2) ;
}

int main() {
  int n , k ;
  cin>>n ;
  for ( int i = 0 ; i < n ; i ++ )
    cin >> input_array[i] ;
  cin >> k ;
  make_seg ( 1 , 0 , n-1 ) ;
  for ( int i = 0 ; i + k-1 < n ; i ++ ) {
    cout<<query(1 , 0 , n-1 , i , i+k-1 )<<" " ;
  }
  return 0 ;
}
