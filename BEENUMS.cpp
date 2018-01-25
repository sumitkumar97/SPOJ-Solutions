#include <iostream>
#include <cmath>
using namespace std;

int main() {
  // your code goes here
  long long n ;
  cin>>n ;
  while ( n != -1 )
    {

      double c , intpart , disc ;
      disc = 1 - 4*((1-n)/3.0) ;
      //cout<<"disc = "<<disc<<endl ;
      if ( n == 0 )
	cout<<"N\n" ;
      else if ( disc >= 0 )
	{
	  c = ( 1 + sqrt ( disc ) ) / 2.0 ;
	  //cout<<"c = "<<c<<endl ;
	  if (  modf( c , &intpart) == 0 && c > 0 )
	    cout<<"Y\n" ;
	  else
	    cout<<"N\n" ;
	}
      else
	cout<<"N\n" ;
      cin>>n ;
    }
  return 0;
}
