#include <iostream>
#include <cstdio>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

int n , arr[1010] ;
ii dp[1010][1010] ;

ii dynamic( int l , int r , int n ) {
  if ( n == 0 )
    return make_pair ( 0 , arr[l] ) ;
  if ( n % 2 == 0 ){
    ii temp ;
    if ( arr[r] > arr[l] ){
      temp = dynamic ( l , r - 1 , n - 1 ) ;
      return make_pair ( temp.first , temp.second + arr[r] ) ;
    }
    temp = dynamic ( l + 1 , r , n - 1 ) ;
    return make_pair ( temp.first , temp.second + arr[l] ) ;
  }
  if (  dp[l][r].first != -1 )
    return dp[l][r] ;
  ii q1 = dynamic( l , r - 1 , n - 1 ) ;
  q1.first += arr[r] ;
  ii q2 = dynamic( l + 1 , r , n - 1 ) ;
  q2.first += arr[l] ;
  return dp[l][r] = ((q1.first > q2.first)? q1 : q2) ;
}

int main() {
  scanf("%d",&n) ;
  int game = 0 ;
  while ( n ) {
    game ++ ;
    for ( int i = 0 ; i < 1010 ; i ++ )
      for ( int j = 0 ; j < 1010 ; j ++ )
	dp[i][j].first = -1 ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d",&arr[i]) ;
    ii ans = dynamic ( 0 , n - 1 , n - 1 ) ;
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n" , game , ans.first - ans.second ) ;
    //    printf("%d %d %d\n",ans.first , ans.second , ans.first - ans.second) ;
    scanf("%d",&n) ;
  }
  return 0 ;
}
