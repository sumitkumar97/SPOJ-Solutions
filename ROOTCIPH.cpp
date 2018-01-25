#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test ;
  scanf("%d",&test) ;
  long long a, b , c , ans ;
  while ( test -- )  {
    scanf("%lld%lld%lld",&a,&b,&c) ;
    ans = (a*a) - (2*b) ;
    printf("%lld\n",ans) ;
  }
  return 0 ;
}
