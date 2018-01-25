#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int test ;
  cin>>test ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      long long a , b , sum ;
      cin>>a>>b>>sum ;
      long long n = (sum*2)/(a+b) ;
      cout<<n<<"\n" ;
      long long ft = (((n-3)*a) - (2*b))/(n-5) ;
      long long d = ( a - ft ) / 2 ;
      for ( int i = 0 ; i < n ; i ++ )
	{
	  cout<<(ft+(i*d))<<" " ;
	}
    }
  return 0;
}
