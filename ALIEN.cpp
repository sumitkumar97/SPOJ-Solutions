#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , arr[100010] ;
  scanf("%d",&test ) ;
  while ( test -- ){
    int at , bt ;
    scanf("%d%d",&at , &bt ) ;
    for ( int i = 0 ; i < at ; i ++ )
      scanf("%d" , &arr[i] ) ;
    int l = -1 , r = -1 , sum = 0 , ans = 0 , stations = 0 ;
    for ( int r = 0 ; r < at ; r ++ ){
      sum += arr[r] ;
      while ( sum > bt && l + 1 <= r ) {
	sum -= arr[l+1] ;
	l ++ ;
      }
      if ( r - l > stations ){
	ans = sum ;
	stations = r - l ;
      }
      if ( r - l == stations && sum < ans )
	ans = sum ;
    }
    printf("%d %d\n",ans , stations ) ;
  }
  return 0 ;
}
