#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int n ;
  scanf("%d",&n) ;
  long long arr[100010][3] ;
  int test = 1 ;
  while ( n ) {
    for ( int i = 0 ; i < n ; i ++ )
      for ( int j = 0 ; j < 3 ; j ++ )
	scanf("%lld",&arr[i][j]) ;
    arr[0][2] += arr[0][1] ;
    arr[1][0] += arr[0][1] ;
    arr[1][1] += min ( arr[1][0] , min (arr[0][1] , arr[0][2] ) );
    arr[1][2] += min ( arr[1][1] , min (arr[0][1] , arr[0][2] ) );
    if ( n == 2 ) {
      printf("%d. %lld\n",test,arr[1][1]) ;
    }
    else {
      long long left , top , ldiag , rdiag ;
      for ( int i = 2 ; i < n ; i ++ ){
	top = arr[i-1][0] ;
	rdiag = arr[i-1][1] ;
	arr[i][0] += min ( top , rdiag ) ;

	top = arr[i-1][1] ;
	ldiag = arr[i-1][0] ;
	rdiag = arr[i-1][2] ;
	left = arr[i][0] ;
	arr[i][1] += min ( min ( top , ldiag ) , min ( rdiag , left ) ) ;

	top = arr[i-1][2] ;
	ldiag = arr[i-1][1] ;
	left = arr[i][1] ;
	arr[i][2] += min ( top , min ( ldiag , left ) ) ;
      }
      printf("%d. %lld\n",test,arr[n-1][1]) ;
    }
    scanf("%d",&n) ;
    test ++ ;
  }
  return 0 ;
}
