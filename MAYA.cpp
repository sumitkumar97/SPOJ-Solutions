#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main(){
  int n ;
  char mystring[1000] ;
  scanf("%d", &n ) ;
  int pre[1000000] ;
  pre[0] = 1 ;
  pre[1] = 20 ;
  pre[2] = 360 ;
  for ( int i = 3 ; pre[i-1] < 10000000 ; i ++ )
    pre[i] = pre[i-1]*20 ;
  while ( n ){
    int ans = 0 ;
    fgets ( mystring , 1000 , stdin ) ;
    while ( n-- ){
      fgets ( mystring , 1000 , stdin ) ;
      int x = 0 ;
      for ( int i = 0 ; i < strlen(mystring) ; i ++ ){
	if ( mystring[i] == '.' )
	  x ++ ;
	if ( mystring[i] == '-' )
	  x += 5 ;
      }
      ans += pre[n]*x ;
    }
    printf("%d\n",ans) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
