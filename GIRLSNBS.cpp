#include <iostream>
using namespace std;
int main()
{
  int g , b ;
  cin>>g>>b ;
  float x ;
  int rem ;
  while ( g != -1 )
    {
      if ( b==0 && g == 0)
	{
	  cout<<"0\n" ;
	}
      else
	{
	  if ( b == g )
	    cout<<"1\n" ;
	  else if ( b < g )
	    {
	      x = float(g) / (b+1) ;
	      if ( x == int (x) )
		{
		  cout<<int(x)<<"\n" ;
		}
	      else
		cout<<int(x) + 1<<"\n" ;
	    }
	  else
	    {
	      x = float(b)/(g+1) ;
	      if ( x == int (x) )
		cout<<int(x)<<"\n" ;
	      else
		cout<<int(x) + 1<<"\n" ;
	    }
	}
      cin>>g>>b ;
    }
  return 0 ;
}
