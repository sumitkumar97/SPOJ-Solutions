#include <iostream>
using namespace std ;

int main() {
  long long n , m , arr[300010] , sum , large ;
  cin>>n>>m ;
  for ( int i = 0 ; i < n ; i ++ )
    cin>>arr[i] ;
  int l , r ;
  l = 0 , r = 0 , large = -1 , sum = 0 ;
  while ( l < n || r < n ) {
    if ( sum <= m && r < n ) {
      sum += arr[r] ;
      r++ ;
    }
    else{
      sum -= arr[l] ;
      l++ ;
    }
    // cout<<sum<<endl ;
    if ( sum <= m && sum > large )
      large = sum ;
  }
  cout<<large ;
}


