#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test  , dsn=5 ;
  cin>>test ;
  char ds[40] ;
  int ttt , tth , tht , thh , htt, hth ,hht , hhh ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      cin>>dsn ;
      ttt = 0 , tth = 0 , tht = 0 ,thh = 0 ,htt = 0 ,hth = 0 , hht = 0 , hhh = 0 ;
      cin>>ds ;
      int i ;
      for ( i = 0 ; i < 38 ; i ++ )
	{
	  if ( ds[i] == 'T' )
	    {
	      if ( ds[i+1] == 'T' )
		{
		  if ( ds[i+2] == 'T' )
		    ttt++ ;
		  else
		    tth++ ;
		}
	      else
		{
		  if ( ds[i+2] == 'T' )
		    tht ++ ;
		  else
		    thh ++ ;
		}
	    }
	  else
	    {
	      if ( ds[i+1] == 'T' )
		{
		  if ( ds[i+2] == 'T' )
		    htt++ ;
		  else
		    hth++ ;
		}
	      else
		{
		  if ( ds[i+2] == 'T' )
		    hht++ ;
		  else
		    hhh++ ;
		}
	    }
	}
      cout<<dsn<<" "<<ttt<<" "<<tth<<" "<<tht<<" "<<thh<<" "<<htt<<" "<<hth<<" "<<hht<<" "<<hhh<<"\n" ;
    }
  return 0 ;
}

