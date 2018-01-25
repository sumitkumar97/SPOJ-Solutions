#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , m , n , arr[110] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    int count[11] = {0} , greater = 0 ;
    scanf("%d%d" , &n , &m ) ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d" , &arr[i] ) ;
      count[arr[i]] ++ ;
    }
    for ( int i = 0 ; i < n ; i ++ )
      if ( arr[i] > arr[m] )
	greater ++ ;
    int i = 0 , ans = greater , j = 9 ;
    while ( greater ){
      while ( count[j] == 0 )
	j -- ;
      if ( arr[i] == j ){
	count[j] -- ;
	greater -- ;
      }
      i = ( i + 1 )%n ;
    }
    while ( i != m ){
      if ( arr[i] == arr[m] )
	ans ++ ;
      i = ( i + 1 )%n ;
    }
    printf("%d\n" , ans + 1 ) ;
  }
  return 0 ;
}
