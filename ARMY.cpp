#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  // your code goes here
  int test ;
  cin>>test ;
  char u[10] ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      gets(u) ;
      int ng , mg ;
      cin>>ng>>mg ;
      int nga[ng] , mga[mg] ;
      for ( int i = 0 ; i < ng ; i ++ )
	{
	  cin>>nga[i] ;
	}
      for ( int i = 0 ; i < mg ; i ++ )
	{
	  cin>>mga[i] ;
	}
      sort(mga,mga+mg) ;
      sort ( nga , nga + ng ) ;
      /*for ( int i = 0 ; i < ng ; i ++ )
	{
	cout<<nga[i]<<"\t" ;
	}*/
      int i = 0 ;
      int j = 0 ;
      int f = 0 ;
      while ( i < ng && j < mg )
	{
	  if ( mga[j] <= nga[i] )
	    {
	      j += 1 ;
	      f = 1 ;
	    }
	  else
	    {
	      f = 2 ;
	      i += 1 ;
	    }
	}
      if ( f == 1 )
	{
	  cout<<"Godzilla\n" ;
	}
      else if ( f == 2 )
	{
	  cout<<"MechaGodzilla\n" ;
	}
      else
	{
	  cout<<"Uncertain\n" ;
	}
    }
  return 0;
}
