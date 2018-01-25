#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int test , n ;
  scanf("%d",&test) ;
  int seive[10000]={0} ;
  int ans[10000] ;
  seive[0] = seive[1] = 1 ;
  for ( int i = 2 ; i < 10000 ; i ++ ) {
    if ( seive[i] == 0 ){
      for ( int j = 2 ; i*j < 10000 ; j ++ ) {
	seive[i*j]++ ;
      }
    }
  }
  int max = 1 ;
  for ( int i = 0 ; i < 10000 ; i ++ ){
    if ( seive[i] >= 3 ){
      ans[max] = i ;
      max++ ;
    }
  }
  while ( test -- ) {
    scanf("%d",&n) ;
    printf("%d\n", ans[n]) ;
  }
  return 0 ;
}
