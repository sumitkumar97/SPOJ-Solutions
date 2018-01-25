#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int stalls[100010] , n , c ;

bool can ( int mindist ){
  if ( mindist == 0 )
    return true ;
  int cows = 1 , i = 0 , j = 0 , nextdist = stalls[i] + mindist ;
  while ( i < n && cows < c ){
    while ( j < n && stalls[j] < nextdist )
      j ++ ;
    if ( j < n )
      cows ++ ;
    i = j ;
    nextdist = stalls[i] + mindist ;
  }
  if ( cows == c )
    return true ;
  return false ;
}

int binary_search ( int low , int high ){
  if ( low >= high )
    return low ;
  int mid = ( low + high )>>1 ;
  if ( can ( mid ) ){
    int x =  binary_search ( mid + 1 , high ) ;
    if ( can ( x ) )
      return x ;
    else
      return mid ;
  }
  else
    return binary_search ( low , mid - 1 ) ;
}

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d%d" , &n , &c ) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &stalls[i] ) ;
    sort ( stalls , stalls + n ) ;
    if ( can( stalls[n-1] - stalls[0] ) )
      printf("%d\n" , stalls[n-1] - stalls[0] ) ;
    else
      printf("%d\n" , binary_search( 0 , stalls[n-1] - stalls[0] ) ) ;
  }
  return 0 ;
}
