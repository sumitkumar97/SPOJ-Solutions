#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

char a[2010] , b[2010] ;
int dp[2010][2010] , a_max , b_max , a_len , b_len ;

int transform ( int a_index , int b_index , int operations ) {
  if ( dp[a_index][b_index] != -1 )
    return operations + dp[a_index][b_index] ;
  if ( a_index >= a_len ) {
    operations += b_len - b_index ;
    return operations ;
  }
  if ( b_index >= b_len ) {
    operations += a_len - a_index ;
    return operations ;
  }
  if ( a[a_index] == b[b_index] )
    return transform ( a_index + 1 , b_index + 1 , operations ) ;
  dp[a_index][b_index] = min ( transform ( a_index + 1 , b_index , 1 ) , min ( transform ( a_index , b_index + 1 , 1 ) , transform ( a_index + 1 , b_index + 1 , 1 ) ) ) ;
  return dp[a_index][b_index] + operations ;
}


int main() {
  int test , lena , lenb ;
  scanf("%d",&test) ;
  while ( test -- ) {
    for ( int i = 0 ; i < 2010 ; i ++ )
      for ( int j = 0 ; j < 2010 ; j ++ )
	dp[i][j] = -1 ;
    scanf("%s",a) ;
    scanf("%s",b) ;
    a_len = strlen(a) ;
    b_len = strlen(b) ;
    printf("%d\n",transform ( 0 , 0 , 0 ) ) ;
  }
  return 0 ;
}



      
