#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std ;

int gcd ( int a , int b ){
  if (  b == 0 )
    return a ;
  return gcd ( b , a % b ) ;
}

int main(){
  int n , arr[100010] , b[100010] ;
  scanf("%d" , &n ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%d", &arr[i] ) ;
  sort ( arr , arr + n ) ;
  for ( int i = 0 ; i < n - 1 ; i ++ )
    b[i] = arr[i+1] - arr[i] ;
  sort ( b , b + n - 1 ) ;
  int diff = b[0] ;
  for ( int i = 1 ; i < n - 1 ; i ++ ){
    if ( b[i] != b[i-1] )
      diff = gcd ( diff , b[i] ) ;
  }
  int x = arr[0] , i = 1 , ans = 0 ;
  while ( x < arr[n-1] ){
    x += diff ;
    if ( x == arr[i] )
      i ++ ;
    else
      ans ++ ;
  }
  printf("%d\n",ans) ;
  return 0 ;
}
