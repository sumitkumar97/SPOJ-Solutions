#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test ;
  scanf("%d",&test ) ;
  int n ;
  while ( test -- ) {
    scanf("%d",&n) ;
    n -= n/2 ;
    printf("%d\n",n) ;
  }
  return 0 ;
}
