#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int main() {
  int n ;
  long long prev , curr , ans ;
  scanf("%d" , &n ) ;
  while ( n ){
    prev = 0 ;
    ans = 0 ;
    while ( n -- ){
      ans += abs ( prev ) ;
      scanf("%lld" , &curr ) ;
      prev += curr ;
    }
    printf("%lld\n" , ans ) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
