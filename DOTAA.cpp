#include <iostream>
using namespace std ;

int main() {
  int test ;
  cin>>test ;
  int heroes , towers , damage , hits , power[500] ;
  while ( test -- ) {
    cin >> heroes >> towers >> damage ;
    hits = 0 ;
    for ( int i = 0 ; i < heroes ; i ++ ) {
      cin>>power[i] ;
      while ( ( power[i] -= damage ) > 0 )
	hits ++ ;
    }
    if ( hits >= towers )
      cout<<"YES\n" ;
    else
      cout<<"NO\n" ;
  }
  return 0 ;
}
