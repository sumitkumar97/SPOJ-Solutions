#include <iostream>
using namespace std ;

int main() {
  int test ;
  cin>>test ;
  int h , w , arr[100][100]={0} , ans[100][100]={0} , l , c , r ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      cin>>h>>w ;
      for ( int i = 0 ; i < h ; i++ )
	{
	  for ( int j = 0 ; j < w ; j ++ )
	    {
	      cin>>arr[i][j] ;
	    }
	}
      int i , j ;
      for ( j = 0 ; j < w ; j ++ )
	ans[0][j] = arr[0][j] ;
      for ( i = 1 ; i < h ; i ++ )
	{
	  if ( ans[i-1][0] > ans[i-1][1] )
	    ans[i][0] = arr[i][0] +  ans[i-1][0] ;
	  else
	    ans[i][0] = arr[i][0] + ans[i-1][1] ;
	  for ( j = 1 ; j < w-1 ; j ++ )
	    {
	      l = 0 , c = 0 , r = 0 ;
	      l = ans[i-1][j-1] + arr[i][j] ;
	      c = ans[i-1][j] + arr[i][j] ;
	      r = ans[i-1][j+1] + arr[i][j] ;
	      if ( l >= r && l >= c )
		ans[i][j] = l ;
	      else if ( c >= r && c >= l )
		ans[i][j] = c ;
	      else
		ans[i][j] = r ;
	    }
	  if ( ans[i-1][w-2] > ans[i-1][w-1] )
	    ans[i][w-1] = arr[i][w-1] + ans[i-1][w-2] ;
	  else
	    ans[i][w-1] = arr[i][w-1] + ans[i-1][w-1] ;
	}
      int largest = 0 ;
      for ( j = 0 ; j < w ; j++ )
	{
	  if ( ans[h-1][j] > largest )
	    largest = ans[h-1][j] ;
	}
      cout<<largest<<"\n" ;
    }
}
