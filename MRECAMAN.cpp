#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int k ;
  bool repeat[4000000]={false} ;
  long long ans[500010] , temp ;

  ans[0] = 0 ;
  repeat[0] = true ;
  for ( int i = 1 ; i <= 500000 ; i ++ ){
    temp = ans[i-1] - i  ;
    if ( temp > 0 && !repeat[temp] ){
      ans[i] = temp ;
    }
    else{
      ans[i] = ans[i-1] + i ;
    }
    repeat[ans[i]] = true ;
  }
  scanf("%d",&k) ;
  while ( k != -1 ){
    printf("%lld\n",ans[k]) ;
    scanf("%d",&k) ;
  }
  return 0 ;
}
