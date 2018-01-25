#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std ;

int main() {
  int test , n ;
  pair<int , int > arr[100010] ;
  scanf("%d",&test) ;
  int start , end , ans ;
  while ( test -- ) {
    scanf("%d",&n) ;
    for ( int i  = 0 ; i < n ; i++ ) {
      scanf("%d%d",&start,&end) ;
      arr[i] = make_pair(end , start) ;
    }
    sort ( arr , arr + n ) ;
    ans = 1 ;
    int endingtime = arr[0].first ;
    for ( int i = 1 ; i < n ; i ++ ) {
      if ( arr[i].second >= endingtime ){
	endingtime = arr[i].first ;
	ans++ ;
      }
    }
    printf("%d\n",ans) ;
  }
  return 0 ;
}
      
