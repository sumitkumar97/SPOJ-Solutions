#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std ;

int temp ;
int binary_search(int l , int r , int key , int *arr , int rightlim) {
  if ( l == r ) {
    temp = abs ( arr[l] - key ) ;
    if ( l-1 >= 0 )
      temp = min ( abs ( arr[l-1] - key ) , temp ) ;
    if ( l + 1 <= rightlim )
      temp = min ( abs ( arr[l+1] - key ) ,temp )  ;
    return temp ;
  }
  int mid = (l+r)/2 ;
  if ( key <= arr[mid] )
    binary_search( l , mid , key , arr ,rightlim ) ;
  else
    binary_search(mid+1 , r , key , arr , rightlim) ;
}

int main() {
  int test ;
  cin>>test ;
  int ans ;
  int firstmount[1010] , secondmount[1010] , nopf , nops ;
  while ( test -- ) {
    ans = 1000001 ;
    cin >> nopf ;
    for ( int i = 0 ; i < nopf ; i ++ )
      cin>> firstmount[i] ;
    cin >> nops ;
    for ( int i = 0 ; i < nops ; i ++ )
      cin >> secondmount[i] ;
    sort ( firstmount , firstmount+nopf ) ;
    sort ( secondmount , secondmount + nops ) ;
    for ( int i = 0 ; i < nopf ; i ++ ) {
      int y = binary_search( 0 , nops-1 , firstmount[i] , secondmount , nops -1 ) ;
      if ( y < ans )
	ans = y ;
    }
    cout<<ans<<"\n" ;
  }
  return 0 ;
}
    
