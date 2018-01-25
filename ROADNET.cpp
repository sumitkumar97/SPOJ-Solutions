#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n , arr[210][210] ;
  scanf("%d" , &test ) ;
  bool neighbours ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i ++ )
      for ( int j = 1 ; j <= n ; j ++ )
	scanf("%d" , &arr[i][j] ) ;
    for ( int i = 1 ; i <= n ; i ++ )
      for ( int j = i + 1 ; j <= n ; j ++ ){
	neighbours = true ;
	for ( int k = 1 ; k <= n ; k ++ )
	  if ( ( j != k && i != k ) && arr[i][j] == ( arr[i][k] + arr[j][k] ) ){
	    neighbours = false ;
	    break ;
	  }
	if ( neighbours )
	  printf("%d %d\n" , i , j ) ;
      }
  }
  return 0 ;
}
	    
