#include <iostream>
#include <cstdio>
using namespace std ;

int dp[2010][2010][3] ;

int fire  ( int , int ) ;
int air   ( int , int ) ;
int water ( int , int ) ;

int fire ( int health , int armor ) {

  if ( health - 20 <= 0 )
    return 0 ;

  if ( dp[health][armor][0] != -1 )
    return dp[health][armor][0] ;

  return dp[health][armor][0] = max ( air ( health - 20 , armor + 5 )  , water ( health - 20 , armor + 5 ) ) + 1 ;
}

int air ( int health , int armor ) {

  if ( dp[health][armor][1] != -1 )
    return dp[health][armor][1] ;

  return dp[health][armor][1] = max ( water ( health + 3 , armor + 2 ) , fire ( health + 3 , armor + 2 ) ) + 1 ;
}

int water ( int health , int armor ) {

  if ( health - 5 <= 0 || armor - 10 <= 0 )
    return 0 ;

  if ( dp[health][armor][2] != -1 )
    return dp[health][armor][2] ;

  return dp[health][armor][2] = max ( air ( health - 5 , armor - 10 ) , fire ( health - 5 ,  armor - 10  )) + 1 ;

}

int main() {
  int test ;
  scanf("%d",&test) ;
  int health , armor ;
  for ( int i = 0 ; i < 2010 ; i ++ )
    for ( int j = 0 ; j < 2010 ; j ++ )
      for ( int k = 0 ; k < 3 ; k ++ )
	dp[i][j][k] = -1 ;
  while ( test -- ) {
    scanf("%d%d",&health , &armor ) ;
    int f = fire ( health , armor ) ;
    int w = water ( health , armor ) ;
    int a = air ( health , armor ) ;
    if ( f > w && f > a )
      printf("%d\n",f) ;
    else  if ( w > a && w > f )
      printf("%d\n" , w ) ;
    else
      printf("%d\n", a ) ;
  }
  return 0 ;
}
    
