#include <iostream>
#include <cstdio>
using namespace std ;

int n , dp[35][2][2][2] ;

int rec ( int iter , int upper , int middle , int lower ){
  int ans = 0 ;
  
  if ( iter > n ){
    if ( !upper && !middle && !lower )
      return 1 ;
    return 0 ;
  }

  if ( dp[iter][upper][middle][lower] != -1 )
    return dp[iter][upper][middle][lower] ;
  
  if ( middle ){
    if ( !upper && !lower )
      ans =  rec ( iter + 1 , 1 , 0 , 1 ) ;
    else if ( !upper )
      ans =  rec ( iter + 1 , 1 , 0 , 0 ) ;
    else if ( !lower )
      ans =  rec ( iter + 1 , 0 , 0 , 1 ) ;
    else
      ans =  rec ( iter + 1 , 0 , 0 , 0 ) ;
  }
  else {
    if ( !upper && !lower )
      ans =  rec ( iter + 1 , 1 , 0 , 0 ) + rec ( iter + 1 , 0 , 0 , 1 ) + rec ( iter + 1 , 1 , 1 , 1 ) ;
    else if ( !upper )
      ans =  rec ( iter + 1 , 0 , 0 , 0 ) + rec ( iter + 1 , 1 , 1 , 0 ) ;
    else if ( !lower )
      ans =  rec ( iter + 1 , 0 , 0 , 0 ) + rec ( iter + 1 , 0 , 1 , 1 ) ;
    else
      ans =  rec ( iter + 1 , 0 , 1 , 0 ) ;
  }
  return dp[iter][upper][lower][middle] = ans ;
}


int main(){
  scanf("%d" , &n ) ;

  while ( n != -1 ){

  for ( int i = 0 ; i < 35 ; i ++ )
    for ( int j = 0 ; j < 2 ; j ++ )
      for ( int k = 0 ; k < 2 ; k ++ )
	for ( int l = 0 ; l < 2 ; l ++ )
	    dp[i][j][k][l] = -1 ;

    
    printf("%d\n" , rec ( 1 , 0 , 0 , 0 ) ) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
