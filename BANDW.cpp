#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int main() {
  char s[510] , t[510] ;
  int n ;
  scanf("%s%s" , s , t ) ;
  while ( s[0] != '*' ){
    n = strlen(s) ;
    int i = 0 , ans = 0 ;
    while ( i < n ){
      while ( i < n && s[i] == t[i] )
	i ++ ;
      if ( i < n )
	ans ++ ;
      while ( i < n && s[i] != t[i] )
	i ++ ;
    }
    printf("%d\n" , ans ) ;
    scanf("%s%s" , s , t ) ;
  }
  return 0 ;
}
