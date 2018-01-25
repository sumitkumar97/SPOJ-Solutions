#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int p , n , dataset ;
  scanf("%d",&p) ;
  long long beginningwith[70][15] = {0} ;
  for ( int i = 0 ; i < 10 ; i ++ )
    beginningwith[1][i] = 1 ;
  for ( int i = 2 ; i <= 64 ; i ++ ) {
    for ( int j = 0 ; j < 10 ; j ++ ) {
      for ( int k = j ; k >= 0 ; k -- )
	beginningwith[i][k] += beginningwith[i-1][j] ;
    }
  }
  while ( p -- ) {
    scanf("%d%d",&dataset,&n) ;
    long long sum = 0 ;
    for ( int i = 0 ; i < 10 ; i ++ )
      sum += beginningwith[n][i] ;
    printf("%d %lld\n",dataset , sum) ;
  }
  return 0 ;
}

    
