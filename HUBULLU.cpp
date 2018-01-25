#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int test ;
  cin>>test ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      int p ;
      long long n ;
      cin>>n>>p ;
      if ( p == 0 )
	cout<<"Airborne wins.\t" ;
      else
	cout<<"Pagfloyd wins.\t" ;
    }
  return 0;
}
