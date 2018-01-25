#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std ;

int val ( char a ){
  if ( a == 'm' )
    return 1000 ;
  if ( a == 'c' )
    return 100 ;
  if ( a == 'x' )
    return 10 ;
  return 1 ;
}

int mcxi_to_decimal ( char *a ){
  int i = 0 , ans = 0 , len = strlen(a) ;
  while ( i < len ){
    if ( a[i] < 97 )
      i ++ ;
    if ( i < len ){
      if ( i - 1 >= 0 && a[i-1] < 97 )
	ans += val(a[i])*( a[i-1] - '0' ) ;
      else
	ans += val(a[i]) ;
    }
    i ++ ;
  }
  return ans ;
}

int main() {
  int n , ans ;
  char a[100] ;
  scanf("%d" , &n ) ;
  while ( n -- ){
    scanf("%s" , a ) ;
    ans = mcxi_to_decimal ( a ) ;
    scanf("%s" , a ) ;
    ans += mcxi_to_decimal ( a ) ;
    //    printf("%d\n" , ans ) ;
    string s = "" ;
    int temp ;
    temp = ans / 1000 ;
    if ( temp > 0 ){
      if ( temp > 1 )
	s = s + (char) (temp + 48) ;
      s = s + 'm' ;
    }
    ans %= 1000 ;
    temp = ans / 100 ;
    if ( temp > 0 ){
      if ( temp > 1 )
	s = s + (char) (temp + 48) ;
      s = s + 'c' ;
    }
    ans %= 100 ;
    temp = ans / 10 ;
    if ( temp > 0 ){
      if ( temp > 1 )
	s = s + (char) (temp + 48) ;
      s = s + 'x' ;
    }
    ans %= 10 ;
    temp = ans ;
    if ( temp > 0 ){
      if ( temp > 1 )
	s = s + (char) (temp + 48) ;
      s = s + 'i' ;
    }
    cout<<s<<"\n" ;
  }
  return 0 ;
}
  
