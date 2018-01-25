#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int arr[100010] ;
bool found ;

void binary_search( int left , int right , int key ) {
  if ( left > right )
    return ;
  int mid = (left + right)/2 ;
  if ( arr[mid] == key ) {
    found = true ;
    return ;
  }
  else if ( key < arr[mid] ){
    binary_search( left , mid-1 , key) ;
  }
  else
    binary_search( mid + 1 , right , key) ;
}

int main() {
  int n , k ;
  scanf("%d%d",&n,&k) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%d",&arr[i] ) ;
  sort ( arr , arr+n ) ;
  long long ans = 0 ;
  for ( int i = 0 ; i < n ; i ++ ) {
    found = false ;
    binary_search ( 0 , n-1 , arr[i]+k ) ;
    if ( found == true )
      ans ++ ;
  }
  printf("%lld",ans) ;
  return 0 ;
}
	 
      
    
    
  
