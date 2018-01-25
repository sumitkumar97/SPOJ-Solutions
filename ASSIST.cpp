#include <iostream>
#include <cstdio>
#include <list>
using namespace std ;

int main() {
  list<int> mylist ;
  for ( int i = 2 ; i <= 34000 ; i ++ )
    mylist.push_back(i) ;

  list<int>::iterator it2 ;
  for ( list<int>::iterator it = mylist.begin() ; it != mylist.end() ; it ++ ){
    it2 = it ;
    int j = *it ;
    it2 ++ ;
    while ( j != 0 && it2 != mylist.end() ){
      j -- ;
      if ( j == 0 ){
	it2 = mylist.erase(it2) ;
	it2 -- ;
	j = *it ;
      }
      it2 ++ ;
    } 
  }
  int n ;
  scanf("%d", &n ) ;
  while ( n ){
    it2 = mylist.begin() ;
    advance ( it2 , n - 1 ) ;
    printf("%d\n" , *it2 ) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
