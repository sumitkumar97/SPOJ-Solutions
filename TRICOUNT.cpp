#include <iostream>
#include <cassert>
using namespace std;
#define ll  long long
ll a [1000010] , b [1000010] ;
ll f( ll n ){
  if ( n > 0)
    return n*(n+1)/2 ; else return 0 ;
}
int main(){
  b[3] = 0 ;for( ll i = 2 ; i <= 1000000 ; i ++ )b[i] = b[i-1] + (i-2)/2 ;
  a[0] = 0 ;a[1] = 1 ;
  for( ll i = 2 ; i <= 1000000 ; i++){a[i] = a[i-1] + (2*i - 1) + f(i-1) + b[i] ;}int t , n ;cin>>t ;while ( t -- ){ cin>>n ;cout<<a[n]<<"\n" ;}
  return 0 ;
}
