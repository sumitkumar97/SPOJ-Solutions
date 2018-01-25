#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int m , k , l ;
  scanf("%d%d%d",&k,&l,&m) ;
  int n ;
  bool win[1000010] = {false} ;
  win[1] = true ;
  win[k] = true ;
  win[l] = true ;
  for ( int i = 2 ; i < 1000010 ; i ++ ) {
    if ( i != k && i != l ) {
      if ( win[i-1] == false )
	win[i] = true ;
      if ( i > k &&  win[i-k] == false )
	win[i] = true ;
      if ( i > l && win[i-l] == false )
	win[i] = true ;
    }
  }
  while ( m -- ) {
    scanf("%d",&n) ;
    if ( win[n] )
      printf("A") ;
    else
      printf("B") ;
  }
  return 0 ;
}
