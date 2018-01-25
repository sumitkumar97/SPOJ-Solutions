#include<stack>
#include <cstring>
#include <iostream>
using namespace std ;

int main()
{
  char c[2010] ;
  int test = 0 ;
  cin>>c ;
  int ans=0 ;
  stack<char> s ;
  while ( c[0] != '-' )
    {
      ans = 0 ;
      for ( int i = 0 ; i < strlen(c) ; i ++ )
	if ( c[i] == '{' )
	  {
	    s.push(c[i]) ;
	    //cout<<"pushed"<<endl ;
	  }
	else if ( c[i] == '}' )
	  {
	    if(s.size() > 0 )
	      {
		s.pop() ;
		//      cout<<"popped"<<endl ;
	      }
	    else
	      {
		ans++ ;
		s.push('{') ;
		//      cout<<"changed"<<endl ;
	      }
	  }
      ans += s.size()/2 ;
      cout<<++test<<". "<<ans<<"\n" ;
      while ( !s.empty())
	s.pop() ;
      cin>>c ;
    }
  return 0 ;
}
