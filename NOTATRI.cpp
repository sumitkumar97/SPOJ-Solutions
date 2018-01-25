#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int n , arr[2010] ;

int binary_search ( int l , int r , int key ){
  if ( l == r )
    return l ;
  int mid = ( l+r )>>1 ;
  if ( arr[mid] == key )
    return mid ;
  if ( key < arr[mid] && l < mid )
    return binary_search ( l , mid - 1 , key ) ;
  if ( key > arr[mid] && mid < r )
    return binary_search ( mid + 1 , r , key ) ;
  if ( l >= mid )
    return l ;
  if ( r <= mid )
    return r ;
}


int main() {
  scanf("%d",&n) ;
  while ( n ) {
    long long ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d",&arr[i]) ;
    sort ( arr , arr + n ) ;
    for ( int i = 0 ; i < n ; i ++ ){
      for ( int j = i+1 ; j < n ; j ++ ){
	int temp = binary_search ( 0 , n -1 , arr[i] + arr[j] ) ;
	while ( arr[temp] <= arr[i] + arr[j] && temp < n ){
	  temp ++ ;
	}
	if ( arr[temp] > arr[i] + arr[j] )
	  ans += (n-1) - temp + 1 ;
      }
    }
    printf("%lld\n",ans) ;
    scanf("%d",&n) ;
  }
  return 0 ;
}
//duplicate elements
