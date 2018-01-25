#include <cstdio>
#include <cstring>
using namespace std ;
long long fun( long long a , long long b )
{
  if ( b == 1 ){return a%10 ;}
  else if ( b == 0 ) return 1 ;
  else{
    if ( b % 2 == 0 ){long long temp = fun(a,b/2) ;temp %= 10 ;return (temp*temp)%10 ;}else{long long temp = fun(a,b/2) ;temp %= 10 ;temp = temp*temp*a ;return temp%10 ;}}
}
int main()
{
  char d[1010] ;long long a , b ; int test ;scanf("%d",&test) ;
  for ( int k = 0 ; k < test ;k ++ )
    {
      scanf("%s",d) ;
      int len = strlen(d) ;
      a = (int)(d[len-1]) - 48 ;
      scanf("%lld",&b) ;
      printf("%lld\n",fun(a,b)) ;
    }
  return 0 ;
}

