#include <iostream>
#include <cstdio>
using namespace std ;
#define lsone(s) (s & -s)

int bit[10000010] ;

void updatebit ( int index ) {
  for ( ; index <= 10000000 ; index += lsone(index) )
    bit[index] += 1 ;
}

long long cs ( int index ){
  long long sum = 0 ;
  for ( ; index ; index -= lsone(index) )
    sum += bit[index] ;
  return sum ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  int n , temp ;
  long long ans ;
  while ( test -- ) {
    scanf("%d",&n) ;
    ans = 0 ;
    for ( int i = 0 ; i < n ; i ++ ) {
      scanf("%d", &temp ) ;
      int index = temp ;
      updatebit(index) ;
      ans += cs(10000000) - cs(index) ;
    }
    printf("%lld\n",ans) ;
    for ( int i = 0 ; i < 10000010 ; i ++ )
      bit[i] = 0 ;
  }
  return 0 ;
}


    
