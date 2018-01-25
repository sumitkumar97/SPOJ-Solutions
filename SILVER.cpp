#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int n ;
  scanf("%d",&n) ;
  int po2 , ans ;
  while ( n != 0 ) {
    po2 = 1 ;
    ans = 0 ;
    while ( n > po2 ) {
      n -= po2 ;
      po2 *= 2 ;
      ans ++ ;
    }
    printf("%d\n",ans) ;
    scanf("%d",&n) ;
  }
  return 0 ;
}
      
