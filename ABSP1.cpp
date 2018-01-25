#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
  int arr[10010] , n , test ;
  scanf("%d",&test) ;
  while ( test -- ) {
    scanf("%d",&n) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d",&arr[i]) ;
    sort ( arr , arr + n ) ;
    long long ans = 0 , sum = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
      sum += arr[i] ;
    for ( int i = 0 ; i < n ; i ++ ) {
      ans += sum - ((n-i)*(long long )arr[i]) ;
      sum -= arr[i] ;
    }
    printf("%lld\n",ans) ;
  }
  return 0 ;
}
