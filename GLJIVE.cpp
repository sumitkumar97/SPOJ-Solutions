#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int arr[11] ;
  for ( int i = 0 ; i < 10 ; i ++ )
    scanf("%d",&arr[i]) ;
  int sum = 0 ;
  int j = 0 , ldiff , rdiff ;
  while ( j < 10 && sum <= 100 ) {
    sum += arr[j] ;
    j++ ;
  }
  if ( j >= 10 && sum <= 100 ) {
    printf("%d",sum) ;
    return 0 ;
  }
  ldiff = 100 - ( sum - arr[j-1] ) ;
  rdiff = sum - 100 ;
  if ( rdiff <= ldiff )
    printf("%d",sum ) ;
  else
    printf("%d",sum - arr[j-1] ) ;
  return 0 ;
}
