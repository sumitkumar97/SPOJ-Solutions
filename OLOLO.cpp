#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int n , ans , temp ;
  scanf("%d%d" , &n , &ans ) ;
  for ( int i = 1 ; i < n ; i ++ ){
    scanf("%d" , &temp ) ;
    ans ^= temp ;
  }
  printf("%d",ans) ;
  return 0 ;
}
