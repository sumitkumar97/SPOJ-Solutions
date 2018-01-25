#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;


int main() {
  int test ;
  scanf("%d",&test) ;
  char stri[13] ;
  bool flag ;
  while ( test -- ) {
    scanf("%s",stri) ;
    flag = true ;
    int k , len = strlen(stri) ;
    for ( k = 0 ; k <= len/2 ; k ++ ) {
      if ( stri[k] != stri[len-1-k] )
	flag = false ;
    }
    if ( flag )
      printf("YES\n") ;
    else
      printf("NO\n") ;
  }
  return 0 ;
}
