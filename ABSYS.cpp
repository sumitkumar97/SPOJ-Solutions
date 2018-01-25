#include <iostream>
#include <cstring>
using namespacestd ;

void chartoint ( char *arr , int &num ) {
  num =0 ;
  for ( int i = 0 ; i < strlen ( arr ) ; i ++ ) {
    num = ( num * 10 ) + ( arr[i] - '0' ) ;
  }
}


int main() {
  int test ;
  cin >> test ;
  bool operand1isnumber , operand2isnumber , sumisnumber ;
  char operand1[40] , operand2[40] , sum[40] , pluso , equalo ;
  int a , b , c;
  while ( test -- ) {
    cin >> operand1 >> pluso >> operand2 >> equalo >> sum  ;
    operand1isnumber = true  ;
    for ( int i = 0 ; i < strlen(operand1) ; i ++ ) {
      if ( isalpha ( operand1[i] ) ) {
	operand1isnumber = false ;
	break ;
      }
    }
    operand2isnumber = true ;
    for ( int i = 0 ; i < strlen(operand2) ; i ++ ) {
      if ( isalpha ( operand2[i] ) ) {
	operand2isnumber = false ;
	break ;
      }
    }
    sumisnumber = true ;
    for ( int i = 0 ; i < strlen(sum) ; i ++ ) {
      if ( isalpha ( sum[i] ) ) {
	sumisnumber = false ;
	break ;
      }
    }
    if ( !operand1isnumber ) {
      chartoint( operand2 , b) ;
      chartoint ( sum , c ) ;
      a = c - b ;
      cout << a << " + " << b << " = " << c << "\n" ;
    }
    else if ( !operand2isnumber ) {
      chartoint( operand1 , a) ;
      chartoint ( sum , c ) ;
      b = c - a ;
      cout << a << " + " << b << " = " << c << "\n" ;
    }
    else if ( !sumisnumber ) {
      chartoint( operand1 , a) ;
      chartoint ( operand2 , b ) ;
      c = a + b;
      cout << a << " + " << b << " = " << c << "\n" ;
    }
  }
  return 0 ;
}
