#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  bool cube[1000010]= {false} ;
  for ( int i = 2 ; i <= 100 ; i ++ ){
    int cub = i * i * i ;
    for ( int j = 1 ; cub*j <= 1000000 ; j ++ )
      cube[cub*j] = true ;
  }
  int position[1000010] , temp = 1 ;
  for ( int i = 1 ; i < 1000010 ; i ++ ){
    if ( !cube[i] ){
      position[i] = temp ;
      temp ++ ;
    }
  }
  int test ;
  scanf("%d",&test ) ;
  for ( int k = 0 ; k < test ; k ++ ){
    int n ;
    scanf("%d",&n) ;
    printf("Case %d: ", k+1 ) ;
    if ( !cube[n] )
      printf("%d\n",position[n]) ;
    else
      printf("Not Cube Free\n") ;
  }
  return 0 ;
}
