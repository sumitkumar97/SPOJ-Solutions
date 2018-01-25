#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n , k , t , f ;
  scanf("%d", &test) ;
  while ( test -- ){
    scanf("%d%d%d%d", &n , &k , &t , &f ) ;
    int ans = ( f - n )/(k - 1 ) ;
    ans += f ;
    printf("%d\n" ,ans ) ;
  }
  return 0 ;
}
