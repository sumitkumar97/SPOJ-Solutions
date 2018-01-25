#include <iostream>
#include <cstdio>
using namespace std ;

int main()
{
  int test ;
  cin>>test ;
  long long r , ians ;
  double ans ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      cin>>r ;
      ians = ( 4  * r * r ) ;
      ans = ians + 0.25 ;
      printf("Case %d: %.2f\n",k+1,ans) ;
    }
}
