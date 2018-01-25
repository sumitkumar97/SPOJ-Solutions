#include <iostream>
#include <cstdio>
#include <map>
using namespace std ;

int bit[30010] ;

int read ( int index ){
  int ans = 0 ;
  while ( index ){
    ans += bit[index] ;
    index -= index & -index ;
  }
  return ans ;
}

void update ( int index ){
  while ( index <= 30000 ){
    bit[index] ++ ;
    index += index & -index ;
  }
}
  

int main() {
  char temp[25] ;
  map<string,int> mymap ;
  int test , n ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i ++ )
      bit[i] = 0 ;
    mymap.clear() ;
    for ( int i = 1 ; i <= n ; i ++ ){
      scanf("%s" , temp ) ;
      mymap[temp] = i ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%s" , temp ) ;
      update ( mymap[temp] ) ;
      ans += read ( n ) - read ( mymap[temp] ) ;
    }

    printf("%d\n" , ans ) ;

  }
  return 0 ;
}
