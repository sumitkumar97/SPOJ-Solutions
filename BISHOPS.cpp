#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int carry , c ;
void ans ( char arr[120] )
{
  carry = -2 ;
  for (int i = strlen(arr)-1 ; i >= 0 ; i-- )
    {
      //printf("%d\n" , int( arr[i]-48)) ;
      c = carry + (2 * ( int (arr[i]) - 48 ) ) ;
      //printf("c=%d\n", c) ;
      carry = c/10 ;
      if ( c >= 0 )
	{
	  arr[i] = char ( (c % 10) + 48 ) ;
	}
      else
	{
	  carry -= 1 ;
	  arr[i] = char ( 58 + c ) ;
	}
      //printf("arr[i] = %c\n",arr[i]) ;
    }
  //printf("carry = %d\n", carry ) ;
  if ( carry > 0 )
    printf("%d%s", carry , arr ) ;
  else
    printf("%s",arr) ;
}
int main() {
  // your code goes here
  char arr[120] ;
  while(scanf("%s",arr)!=EOF)
    {
      if ( strlen(arr) == 1 && arr[0]=='0' )
	cout<<"0\n" ;
      else if ( strlen(arr)==1 && arr[0]=='1')
	cout<<"1\n" ;
      else
	{
	  ans ( arr ) ;
	  cout<<"\n" ;
	}
    }
  return 0;
}
