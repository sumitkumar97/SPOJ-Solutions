#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std ;

int main() {
  char identifier[110] , i , len ;
  bool error = false ;
  int java , cpp ;
  while ( cin >> identifier ) {
    java = 0 , cpp = 0 ;
    error = false ;
    len = strlen(identifier) ;
    if ( isupper(identifier[0]) )
      error = true ;
    if ( identifier[0] == '_' )
      error = true ;
    if ( identifier[len -1 ] == '_')
      error = true ;
    for ( i = 0 ; i < len ; i ++ ) {
      if ( identifier[i] == '_' )
	cpp = 1 ;
      if ( isupper(identifier[i]) ) {
	java = 1 ;
      }
      if ( i > 0 && identifier[i] == '_' && identifier[i-1] == '_' )
	error = true ;
      if ( java && cpp ) {
	error = true ;
	break ;
      }
    }
    if ( !error ) {
      if ( cpp ) {
	printf("%c",identifier[0]) ;
	for ( i = 1 ; i < len ; i ++ ) {
	  if ( identifier[i] == '_' ) {
	    i++ ;
	    identifier[i] = toupper(identifier[i]) ;
	  }
	  printf("%c",identifier[i]) ;
	}
	printf("\n") ;
      }
      else {
	for ( i = 0 ; i < len ; i ++ ) {
	  if ( isupper(identifier[i]) )
	    printf("_") ;
	  printf("%c",tolower(identifier[i])) ;
	}
	printf("\n") ;
      }
    }
    else
      printf("Error!\n") ;
  }
  return 0 ;
}






