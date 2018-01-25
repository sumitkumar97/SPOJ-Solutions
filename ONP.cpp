#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std ;

int top = -1 ;
char s[410] , pos[420] , in[420] ;

int prec(char c)
{
  if ( c == '+' || c == '-' )
    return 1 ;
  if ( c == '*' || c == '/' )
    return 2 ;
  if ( c == '^')
    return 3 ;
  else
    return 0 ;
}

void push ( char c)
{
  top ++ ;
  s[top]= c ;
}

char pop ()
{
  char temp ;
  temp = s[top] ;
  top -- ;
  return temp ;
}

int main()
{
  int test , j ;
  char ch ;
  scanf("%d",&test ) ;
  fgets(in,405,stdin) ;
  for ( int k = 0 ; k < test ; k ++ )
    {
      fgets(in,405,stdin) ;
      j = 0 , top = -1 ;
      int len = strlen(in) ;
      for ( int i = 0 ; i < len ; i ++ )
	{
	  ch = in[i] ;
	  if ( isalpha(ch) )
	    {
	      pos[j] = ch ;
	      j++ ;
	    }
	  else if ( ch == '(' )
	    push(ch) ;
	  else if ( ch == ')' )
	    {
	      while ( s[top] != '(' )
		{
		  pos[j] = pop() ;
		  j++ ;
		}
	      pop() ;
	    }
	  else
	    {
	      while ( prec(s[top]) > prec(ch) )
		{
		  pos[j] = pop() ;
		  j ++ ;
		}
	      push(ch) ;
	    }
	}
      pos[j] = '\0' ;
      j++ ;
      puts(pos) ;
    }
  return 0 ;
}
       
	    

