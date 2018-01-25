#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n ;

long long dp[10010], arr[10010]  ;

long long rec(int i)
{
  if ( i > n -1 )
    return 0 ;
  if ( i == n-1 )
    return arr[i] ;
  if ( dp[i] != -1 )
    return dp[i] ;
  return dp[i] = max(arr[i]+rec(i+2) , rec(i+1) ) ;
}

int main (){
  int test , q = 1 ;
  cin >> test;
  while(test--){
    cin>>n ;
    for (int i = 0 ; i < n ; i ++ )
      cin>>arr[i] ;
    for(int i = 0 ; i <= n ; i ++)
      dp[i] = -1 ;
    cout<<"Case "<<q<<": "<<rec(0)<<"\n" ;
    q++ ;
  }
  return 0 ;
}
