#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main() {
  int test ;
  char arr[1000000] ;
  scanf("%d", &test ) ;
  fgets ( arr , 1000000 , stdin ) ;
  while ( test -- ){
    fgets ( arr , 1000000 , stdin ) ;
    int i = 0 , currlen = 0 , prevlen = -10 , count = 0 , maxi = 0 ;
    while ( i < strlen(arr)-1 ){
      while ( arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\r' )
	i ++ ;
      if ( i == strlen(arr)-1 )
	break ;
      while ( arr[i] != ' ' && arr[i] != '\n' && arr[i] != '\r' && arr[i] != '\t' ) {
	currlen ++ ;
	i ++ ;
      }
      if ( currlen == prevlen && currlen )
	count ++ ;
      else
	count = 1 ;
      if ( count > maxi )
	maxi = count ;
      prevlen = currlen ;
      currlen = 0 ;
    }
    printf("%d\n",maxi) ;
  }
  return 0 ;
}
