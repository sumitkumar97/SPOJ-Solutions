#include <iostream>
#include <cstdio>
#define N 10000007
using namespace std ;

typedef long long ll ;

ll modular_exponentiation ( ll a , ll x ) {
  if ( x == 1 )
    return a ;
  if ( x % 2 == 0 ){
    ll temp = modular_exponentiation ( a , x>>1 ) % N ;
    return (temp*temp)% N ;
  }
  else {
    ll temp = modular_exponentiation ( a , x>>1 ) % N ;
    return (((temp*temp)%N)* a )%N ;
  }
}

int main() {
  long long n , k ;
  scanf("%lld%lld",&n,&k) ;
  while ( n ) {
    ll ans = ( modular_exponentiation ( n , k ) + (modular_exponentiation ( n-1 , k )<<1) + modular_exponentiation ( n , n ) + (modular_exponentiation ( n - 1 , n - 1 )<<1) )% N ;
    printf("%lld\n",ans) ;
    scanf("%lld%lld",&n,&k) ;
  }
  return 0 ;
}
