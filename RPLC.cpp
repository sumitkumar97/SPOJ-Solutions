#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , n ;
  long long input ,  min , sum ;
  scanf("%d",&test) ;
  for ( int k = 1 ; k <= test ; k ++ ){
    scanf("%d",&n) ;
    min = 1000000 ;
    sum = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
      scanf("%lld", &input ) ;
      sum += input ;
      if ( sum < min )
	min = sum ;
    }
    if ( min >= 0 )
      printf("Scenario #%d: 1\n", k ) ;
    else
      printf("Scenario #%d: %lld\n",k,-(min-1)) ;
  }
  return 0 ;
}




    
