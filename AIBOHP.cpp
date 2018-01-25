#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int dp [6101][6101] ;
string s;
int rec ( int l , int r ){
  if ( l == r)
    return 0 ;
  if ( dp[l] [r] != -1 )
    return dp[l][r] ;
  if( s[l] == s[r])
    return dp[l][r] = rec ( l+1, r-1 );
  else
    return dp[l][r] = min(1 + rec(l, r-1) , 1 + rec(l+1, r));
}

int main (){
  int test;
  cin >> test;
  while(test--){
    cin >> s;
    for(int i = 0 ; i < s.length() ; i ++)
      for(int j = 0 ; j < s.length(); j++)
	dp[i][j] = -1 ;
    cout << rec (0, s.length()-1) << "\n" ;
  }
}
