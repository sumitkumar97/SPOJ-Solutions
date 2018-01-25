#include <iostream>
#include <cstdio>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

int main() {
  // your code goes here
  int l ;
  cin>>l ;
  float ans ;
  //cout<<M_PI<<endl ;
  while ( l )
    {
      ans = (l*l)/(2*M_PI) ;
      printf("%.2f\n",ans) ;
      cin>>l ;
    }
  return 0;
}
