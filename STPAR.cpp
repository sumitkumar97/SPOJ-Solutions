#include <iostream>
using namespace std;

int main() {
  // your code goes here
  int n ;
  cin>>n ;
  while ( n )
    {
      int arr[n] , stack[n] ;
      int i , top = -1 ;
      for ( i = 0 ; i < n ; i ++ )
	{
	  cin>>arr[i] ;
	}
      int last = arr[i-1] ;
      i = 1 ;
      int t = 0 ;
      for ( i = 1 ; i <= n ; i ++ )
	{
	  if ( arr[i-1] != i )
	    {
	      if (top >= 0 && i == stack[top] )
		{
		  for ( int k = n-1 ; k > i - 1 ; k -- )
		    {
		      arr[k] = arr[k-1] ;
		    }
		  arr[i-1] = stack[top] ;
		  top -= 1 ;
		}
	      else
		{
		  top += 1 ;
		  stack[top] = arr[i-1] ;
		  int j ;
		  for ( j = i ; j < n ; j++ )
		    {
		      arr[j-1] = arr[j] ;
		    }
		  i -= 1 ;
		}
	    }
	  if ( arr[i-1] == last )
	    {
	      t = i ;
	      break ;
	    }
	}
      for ( int j = t ; j < n ; j ++ )
	{
	  arr[j] =  stack[top] ;
	  top -= 1 ;
	}
      bool y = false ;
      for ( i = 1 ; i <= n ; i ++ )
	{
	  if ( arr[i-1] == i )
	    {
	      y = true ;
	    }
	  else
	    {
	      y = false ;
	      break ;
	    }
	}
      if ( y == true )
	cout<<"yes\n" ;
      else
	cout<<"no\n" ;
      cin>>n ;
    }
  return 0;
}
