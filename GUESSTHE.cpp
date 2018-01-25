#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long ll ;

ll gcd ( ll a , ll b  ){
  if ( b == 0 )
    return a ;
  return gcd ( b , a%b ) ;
}

int main() {
  char s[25] ;
  ll n ;
  scanf("%s" , s ) ;
  while ( s[0] != '*' ){
    n = 1 ;
    bool flag = false ;
    for ( int i = 1 ; (!flag) && i <= strlen(s) ; i ++ ){
      if ( s[i-1] == 'Y' ){
	for ( int j = i - 1 ; j > 0 ; j -- ){
	  if ( i % j == 0 && n % j != 0 ){
	    flag = true ;
	    break ;
	  }
	}
	n = ( n * i )/gcd ( n , (ll)i ) ;
      }
      else{
	if ( n % i == 0 ){
	  flag = true ;
	  break ;
	}
      }
    }
    if ( flag )
      printf("-1\n") ;
    else
      printf("%lld\n" , n )  ;
    scanf("%s" , s ) ;
  }
  return 0 ;
}
