#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int arr[4] , caseno = 0 ;
  while ( scanf("%d" , &arr[0] ) != EOF ){
    caseno ++ ;
    for ( int i = 1 ; i < 4 ; i ++ )
      scanf("%d" , &arr[i] ) ;
    sort ( arr , arr + 4 ) ;
    printf("Case %d: %d\n" , caseno , arr[2] + arr[3] ) ;
  }
  return 0 ;
}
