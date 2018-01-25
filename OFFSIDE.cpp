#include <iostream>
#include <algorithm>
using namespace std;

int b[1000] , c[1000] ;
int main() {
  // your code goes here
  int a , d ;
  cin>>a>>d ;
  while ( a!=0 || d!=0 )
    {
      for ( int i = 0 ; i < a ; i++ )
	{
	  cin>>b[i] ;
	}
      for ( int i = 0 ; i < d ; i ++ )
	{
	  cin>>c[i] ;
	}
      sort(b,b+a) ;
      sort(c,c+d) ;
      if ( b[0] >= c[1] )
	cout<<"N\n" ;
      else
	cout<<"Y\n" ;
      cin>>a>>d ;
    }
  return 0;
}
