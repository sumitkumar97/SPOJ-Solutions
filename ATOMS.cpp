#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int main() {
  int test ;
  scanf("%d", &test ) ;
  long long n , k , m ;
  while ( test -- ){
    scanf("%lld%lld%lld", &n , &k , &m ) ;
    if ( m <= n )
      printf("0\n") ;
    else {
      m /= n ;
      long long pp[1000000] ;
      pp[0] = 1 ;
      int x = 0 ;
      m /= k ;
      if ( pp[x] > m ){
	printf("0\n") ;
	continue ;
      }
      while ( pp[x] <= m ){
	x ++ ;
	pp[x] = pp[x-1] * k ;
      }
      m *= k ;
      while ( pp[x] > m )
	x -- ;
      printf("%d\n",x) ;
    }
  }
  return 0 ;
}
