#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    if ( n % 2 )
      printf("Sorry Shaktiman\n") ;
    else
      printf("Thankyou Shaktiman\n") ;
  }
  return 0 ;
}
