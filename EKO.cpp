#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int n , required , arr[1000010] ;
  long long sum = 0  ;
  scanf("%d%d" , &n , &required ) ;
  for ( int i = 0 ; i < n ; i ++ )
    scanf("%d" , &arr[i] ) ;
  sort ( arr , arr + n ) ;
  int  count = 1 , iter = n-2 ;
  while ( sum < required ){
    sum += ( arr[iter+1] - arr[iter] )*count ;
    iter -- ;
    count ++ ;
  }
  count -- ;
  iter ++ ;
  long long temp = sum - required ;
  if ( temp ){
    temp /= count ;
    arr[iter] += temp ;
  }
  printf("%d\n" , arr[iter] ) ;
  return 0 ;
}
