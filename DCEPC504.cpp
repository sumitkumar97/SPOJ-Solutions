#include <iostream>
#include <cstdio>
using namespace std ;

typedef long long ll ;

bool ans[(int)1e8] ;

bool rec ( ll index ){
  if ( index < (int)1e8 )
    return ans[index] ;

  ll lim = 0 ;
  while ( index > (ll)1<<lim ){
    lim ++ ;
  }

  return !rec(index - ((ll)1 << (lim-1)) ) ;
}

int  main() {
  int test , n ;
  scanf("%d" , &test ) ;
  ans[1] = true ;
  int curr = 1 , pow = 0 ;

  while ( curr < (int)1e8 ) {
    for ( int i = 1 ; (i <= (1<<pow)) && curr + i < (int)1e8 ; i ++ ){
      ans[curr + i] = !ans[i] ;
    }
    pow ++ ;
    curr = (1<<pow) ;
  }
  long long k ;
  while ( test -- ){
    scanf("%d%lld" , &n , &k ) ;
    if ( rec ( k ) )
      printf("Male\n") ;
    else
      printf("Female\n") ;

  }
  return 0 ;
}
