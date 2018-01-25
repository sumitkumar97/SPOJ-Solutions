#include <iostream>
using namespace std ;

int n ;
long dp[2010][2010] , arr[2010] ;
long rec ( int l , int r , int a )
{
  if ( l == r )
    return arr[l]*a ;
  if ( dp[l][r] != -1 )
    return dp[l][r] ;
  return dp[l][r] = max((a*arr[l])+rec(l+1,r,a+1) ,(a*arr[r])+rec(l,r-1,a+1)) ;
}


int main()
{
  cin>>n ;
  for ( int i = 0 ; i < n ; i ++ )
    cin>>arr[i] ;
  for ( int i = 0 ; i < n ; i ++ )
    for ( int j = 0 ; j < n ; j ++ )
      dp[i][j] = -1 ;
  cout<<rec(0,n-1,1) ;
  return 0 ;
}
