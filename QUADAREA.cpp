#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

int main() {
  int test ;
  cin>>test ;
  double a , b , c , d , s , area ;
  while ( test -- ) {
    cin >> a >> b >> c >> d ;
    s = ( a + b + c + d )/2 ;
    area = sqrt ( ( s - a ) * ( s - b ) * ( s - c ) * ( s - d ) ) ;
    std::cout << std::fixed;
    std::cout << std::setprecision(2) << area << '\n';
  }
  return 0 ;
}


