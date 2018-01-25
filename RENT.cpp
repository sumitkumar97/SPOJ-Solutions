#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int n , dp[10001] ;


struct struct_order {
  int st , dur , price ;
} order[10010] ;

int starting_time[10010] ;


bool custom_sort ( struct_order a , struct_order b ){
  return ( a.st < b.st || ( a.st == b.st && ( a.st + a.dur < b.st + b.dur ) ) ) ;
}

int rec ( int iter ){
  int poend = order[iter].st + order[iter].dur , newiter ;
  if ( iter >= n )
    return 0 ;

  if ( dp[iter] != -1 )
    return dp[iter] ;

  return dp[iter] = max ( rec(iter+1) , order[iter].price + rec ( upper_bound ( starting_time + iter , starting_time + n , poend - 1 ) - starting_time ) ) ;
}
       

int main() {
  int test ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i ++ )
      dp[i] = -1 ;

    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d%d%d" , &order[i].st , &order[i].dur , &order[i].price ) ;
      starting_time[i] = order[i].st ;
    }

    sort ( order , order + n , custom_sort ) ;

    sort ( starting_time , starting_time + n ) ;

    printf("%d\n" , rec(0) ) ;
  }
  return 0 ;
}
