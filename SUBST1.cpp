#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int SA[50010] , tempSA[50010] , RA[50010] , tempRA[50010] , n ;
char s[50010] ;

void counting ( int k ){

  int count[50010] = {0} , temp , maxi = max ( 300 , n ) ;
  for ( int i = 0 ; i < n ; i ++ )
    count[ i + k < n ? RA[i+k] : 0 ]++ ;

  for ( int i = 0 , sum = 0 ; i < maxi ; i ++ ){
    temp = count[i] ;
    count[i] = sum ;
    sum += temp ;
  }

  for ( int i = 0 ; i < n ; i ++ )
    tempSA[ count[ SA[i] + k < n ? RA[ SA[i] + k] : 0 ] ++ ] = SA[i] ;

  for ( int i = 0 ; i < n ; i ++ ){
    SA[i] = tempSA[i] ;
  }
}

void constructSA(){

  for ( int i = 0 ; i < n ; i ++ )
    SA[i] = i ;

  for ( int i = 0 ; i < n ; i ++ )
    RA[i] = s[i] ;

  for ( int k = 1 ; k < n ; k <<= 1 ){
    counting(k) ;
    counting(0) ;

    int r ;
    tempRA[ SA[0] ] = r = 0 ;

    for ( int i = 1 ; i < n ; i ++ ){
      tempRA[ SA[i] ] = ( RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1] + k] ) ? r : ++r ;
    }

    for ( int i = 0 ; i < n ; i ++ ){

      RA[i] = tempRA[i] ;
    }

    if ( RA[ SA[n-1] ] == n - 1 )
      break ;

  }
}

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%s" , s ) ;
    n = strlen(s) ;
    s[n++] = (char) 1 ;
    constructSA() ;
    
    int ans = 0 ;

    for ( int i = 1 ; i < n ; i ++ ){
      int k = 0 ;
      while ( SA[i-1] + k < n - 1 && SA[i] + k < n - 1 && s[ SA[i-1] + k ] == s[ SA[i] + k ] )
	k ++ ;
      ans += n - 1 - ( SA[i] + k ) ;
    }
    printf("%d\n" , ans ) ;
  }
  return 0 ;
}
