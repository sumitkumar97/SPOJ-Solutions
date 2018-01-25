#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

typedef long long ll ;

ll  gcd ( ll a , ll b ){
  if ( b == 0 )
    return a ;
  return gcd ( b , a%b ) ;
}

int main(){
  int test ;
  ll s1 , s2 ;
  scanf("%d",&test) ;
  while ( test -- ){
    scanf("%lld%lld" , &s1 , &s2 ) ;
    ll temp = -1 ;
    bool y =  false ;
    if ( s1*s2 < 0 )
      y = true ;
    s1 = abs ( s1 ) ;
    s2 = abs ( s2 ) ;
    if ( y )
      temp += 2 ;
    int slower = s1 < s2 ? s1 : s2 ;
    int faster = s1 > s2 ? s1 : s2 ;
    ll x = (s1*s2)/gcd(s1,s2) ;
    temp += x/slower ;
    if ( !y )
      temp -= (x/faster) - 1 ;
    else
      temp += (x/faster) - 1 ;
    printf("%lld\n",temp) ;
  }
  return 0 ;
}
