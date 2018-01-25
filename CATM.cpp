#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int n , m , test , mx , my , c1x , c1y , c2x , c2y ;
  scanf("%d%d%d" , &n , &m , &test ) ;
  while ( test -- ){
    scanf("%d%d%d%d%d%d" , &my , &mx , &c1y , &c1x , &c2y , &c2x ) ;
    if ( (c1x > c2x && c1y > c2y && ((c1x - c2x) == ( c1y - c2y )) && mx > c2x && c1x > mx && c1y > my && my > c2y  ) || (c2x > c1x && c2y > c1y && (( c2x - c1x ) == ( c2y - c1y )) && c2x > mx && mx > c1x && c2y > my && my > c1y ) ){
      if ( (c1x - mx) == (c1y - my) )
	printf("NO\n") ;
      else
	printf("YES\n") ;
    }
    else if ( ( c1x > c2x && c1y < c2y && ( c1x - c2x == c2y - c1y ) && c1x > mx && mx > c2x && c1y < my && my < c2y  ) || ( c1x < c2x && c1y > c2y && ( c2x - c1x == c1y - c2y ) && c1x < mx && mx < c2x && c1y > my && my > c2y ) ){
      if ( c1x - mx == my - c1y )
	printf("NO\n") ;
      else
	printf("YES\n") ;
    }
    else
      printf("YES\n") ;
  }
  return 0 ;
}
  
