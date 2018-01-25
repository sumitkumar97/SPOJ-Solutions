#include <iostream>
#include <cstdio>
using namespace std ;

int rec ( int n , int d ){
  if ( n == 1 )
    return 1 ;
  return ( rec ( n - 1 , d ) + d - 1 ) % n + 1 ;
}
  

int main() {
  int n , d ;
  scanf("%d%d" , &n , &d ) ;  
  while ( n ){
    printf("%d %d %d\n" , n , d , rec ( n , d ) ) ;
    scanf("%d%d" , &n , &d ) ;  
  }
  return 0 ;
}
    
    


