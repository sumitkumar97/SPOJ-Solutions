#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;

int gcd ( int a , int b ){
  if ( b == 0 )
    return a ;
  return gcd ( b , a % b ) ;
}

int main(){
  long long w , h ;
  scanf("%lld%lld",&w,&h) ;
  while ( w ){
    long long pro , edge , l , b ; // l = tiles along length and b = tiles along breadth
    pro = ( w * h ) ;
    edge = pro / gcd ( w , h ) ;
    l = edge / w ;
    b = edge / h ;
    printf("%lld\n",l*b) ;
    scanf("%lld%lld",&w,&h) ;
  }
  return 0 ;
}
  
