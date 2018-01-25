#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std ;


int main() {
  double u , v , w , U , V , W , x , y , z , volume , temp ;
   int test ;
  scanf("%d",&test) ;
  while ( test -- ) {
    scanf("%lf%lf%lf%lf%lf%lf",&w,&v,&u,&U,&V,&W) ;
    volume = 1/12.0 ;
    x = (v*v) + (w*w) - (U*U) ;
    y = (w*w) + (u*u) - (V*V) ;
    z = (u*u) + (v*v) - (W*W) ;
    temp = (4*u*u*v*v*w*w) - (u*u*x*x) - (v*v*y*y) - (w*w*z*z) + (x*y*z) ;
    volume *= sqrt(temp) ;
    printf("%.4lf\n",volume) ;
  }
  return 0 ;
}
    
    
