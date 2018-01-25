#include <iostream>
#include <cstdio>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

int n , budget , fun[110] , cost[110] ;
ii dp[510][110] ;

ii rec ( int current_budget , int party ) {
  if ( dp[current_budget][party].first != -1 )
    return dp[current_budget][party] ;
  if ( party < n - 1 )
    if ( current_budget >= cost[party] ) {
      ii ret1 = rec ( current_budget - cost[party] , party + 1 ) ;
      ret1.first += fun[party] ;
      ret1.second += cost[party] ;
      ii ret2 = rec ( current_budget , party + 1 ) ;
      if ( ret1.first < ret2.first )
	return dp[current_budget][party] = ret2 ;
      else if ( ret1.first > ret2.first )
	return dp[current_budget][party] = ret1 ;
      else {
	if (  ret2.second < ret1.second )
	  return dp[current_budget][party] = ret2 ;
	else
	  return dp[current_budget][party] = ret1 ;
      }
    }
    else
      return dp[current_budget][party] = rec ( current_budget , party + 1 ) ;
  if ( party == n - 1 && current_budget >= cost[party] )
    return dp[current_budget][party] = make_pair ( fun[party] , cost[party] ) ;
  return make_pair ( 0 , 0 ) ;
}



int main() {
  scanf("%d%d",&budget , &n) ;
  while ( budget || n ) {
    for ( int i = 0 ; i < 510 ; i ++ )
      for ( int j = 0 ; j < 110 ; j ++ )
	dp[i][j].first = -1 ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d%d",&cost[i],&fun[i]) ;
    ii ans = rec( budget , 0 ) ;
    printf("%d %d\n",ans.second , ans.first) ;
    scanf("%d%d",&budget , &n) ;
  }
  return 0 ;
}
  
