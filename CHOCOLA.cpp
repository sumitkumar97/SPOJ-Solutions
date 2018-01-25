#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;

typedef pair<int,int > ii ;

bool custom_sort ( ii a , ii b ){
  return a.second < b.second ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  int m , n ;
  ii arr[2010] ;
  while ( test -- ) {
    scanf("%d%d",&m,&n) ;
    int temp ;
    for ( int i = 1 ; i < m ; i ++ ){
      scanf("%d",&temp ) ;
      arr[i].first = 1 ;
      arr[i].second = temp ;
    }
    for ( int i = m  ; i < m + n - 1 ; i ++ ){
      scanf("%d",&temp ) ;
      arr[i].first = 2 ;
      arr[i].second = temp ;
    }
    int  div1 = 1 , div2 = 1 , cost = 0 ;
    sort ( arr + 1 , arr + m + n - 1 , custom_sort ) ;
    for ( int i = m + n - 2 ; i > 0 ; i -- ){
      if ( arr[i].first == 1 ) {
	div1 ++ ;
	cost += arr[i].second * div2 ;
      }
      else {
	div2 ++ ;
	cost += arr[i].second * div1 ;
      }
    }
    printf("%d\n",cost) ;
  }
  return 0 ;
}
