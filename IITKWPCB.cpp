#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test ;
  long long n ;
  scanf("%d",&test) ;
  while ( test -- ){
    scanf("%lld",&n) ;
    if ( n <= 2 ){
      printf("1\n") ;
      continue ;
    }
    if ( n % 2 == 0 ){
      long long temp = (n>>1) - 1 ; 
      if ( temp % 2 == 0 )
	printf("%lld\n",temp-1) ;
      else
	printf("%lld\n",temp) ;
    }
    else
      printf("%lld\n",n>>1) ;
  }
  return 0 ;
}
    
