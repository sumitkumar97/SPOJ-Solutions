#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  long long n ;
  scanf("%lld",&n) ;
  long long arr[1010] ;
  arr[1] = 5 ;
  for ( int i = 2 ; i <= 1000 ; i ++ )
    arr[i] = arr[i-1] + 7 + (i-2)*3 ;
  while ( n ) {
    printf("%lld\n",arr[n]);
    scanf("%lld",&n) ;
  }
  return 0 ;
}
