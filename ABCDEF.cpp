#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int a[1000010] , b[1000010] , n , arr[110] , acount = 0 , bcount = 0 ;
  scanf("%d" , &n ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%d" , &arr[i] ) ;
  for ( int i = 0 ; i < n ; i ++ )
    for ( int j = 0 ; j < n ; j ++ )
      for ( int k = 0 ; k < n ; k ++ ){
	a[acount] = (arr[i]*arr[j])+arr[k] ;
	acount ++ ;
	if ( arr[k] != 0 ){
	  b[bcount] = (arr[i]+arr[j])*arr[k] ;
	  bcount ++ ;
	}
      }
  sort ( b , b + bcount ) ;
  int ans = 0 ;
  for ( int i = 0 ; i < acount ; i ++ ){
    int index = lower_bound ( b , b + bcount , a[i] ) - b ;
    while ( b[index] == a[i] ){
      ans ++ ;
      index ++ ;
    }
  }
  printf("%d\n" , ans ) ;
  return 0 ;
}
