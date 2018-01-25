#include <iostream>
#include <cstdio>
using namespace std ;

int  ag_checkpts = 0 , tom_checkpts = 0 ;
int ag[2010] , tom[2010] ;

int dp[2010][2010] ;

int rec ( int first , int second , int count ){
  int app1 = -1 , app2 = -1  , app3 = -1 , app4 = -1 , maxi ;
  if ( dp[first][second] != -1 )
    return dp[first][second] ;
  if ( second < tom_checkpts - 1 ){
    app1 = rec ( first , second + 1 , count ) ;
  }
  if ( first < ag_checkpts -1 ){
    app2 = rec ( first + 1 , second , count ) ;
  }
  if ( second < tom_checkpts -1 && first < ag_checkpts - 1 ){
    app3 = rec ( first + 1 ,second + 1 , count ) ;
    if ( ag[first] == tom[second] )
      app4 = app3 + 1 ;
  }
  maxi = max ( max ( app1 , app2 ) , max ( app3 , app4 ) ) ;
  if ( maxi > 0 )
    return dp[first][second] = maxi ;
  if ( ag[first] == tom[second] )
    return dp[first][second] = count+1 ;
  else
    return dp[first][second] = count ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test -- ) {
    ag_checkpts = 0 , tom_checkpts = 0 ;
    scanf("%d",&ag[ag_checkpts]) ;
    while ( ag[ag_checkpts] ){
      ag_checkpts++ ;
      scanf("%d",&ag[ag_checkpts]) ;
    }
    int control = 1 ;
    int ans = 0 ;
    while ( control ){
      scanf("%d",&tom[tom_checkpts] ) ;
      control = tom[tom_checkpts] ;
      while ( tom[tom_checkpts] ){
	tom_checkpts ++ ;
	scanf("%d",&tom[tom_checkpts]) ;
      }
      for ( int i = 0 ; i < 2010 ; i ++ )
	for ( int j = 0 ; j < 2010 ; j ++ )
	  dp[i][j] = -1 ;
      if ( control ){
	ans = max ( rec ( 0 , 0 , 0 ) , ans ) ;
      }
      tom_checkpts = 0  ;
    }
    printf("%d\n",ans) ;
  }
  return 0 ;
}

