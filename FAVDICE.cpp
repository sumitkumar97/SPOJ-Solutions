#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n ;
  float ans ;
  scanf("%d",&test) ;
  while ( test -- ){
    scanf("%d",&n) ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; i ++ )
      ans += 1.0/i ;
    ans *= n ;
    printf("%.2f\n",ans) ;
  }
  return 0 ;
}
