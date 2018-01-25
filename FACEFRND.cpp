#include <iostream>
using namespace std ;

bool frnd[10010] , counted[10010] ;

int main() {
  int n ;
  cin>>n ;
  int temp , count = 0 , index = 0 , m , arr[10010] ;
  for ( int i = 0 ; i < n ; i ++ ) {
    cin>>temp ;
    frnd[temp] = true ;
    cin>>m ;
    for ( int j = 0 ; j < m ; j ++ ) {
      cin>>arr[index] ;
      index ++ ;
    }
  }
  for ( int i = 0 ; i < index ; i ++ ) {
    if ( !frnd[arr[i]] && !counted[arr[i]] ) {
      count ++ ;
      //      cout<<arr[i]<<endl ;
      counted[arr[i]] = true ;
    }
  }
  cout<<count ;
  return 0 ;
}
    
