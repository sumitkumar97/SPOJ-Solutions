#include <iostream>
#include <cstdio>
using namespace std ;

int rotate_binary(int number){
  int res = 0;
  while(number>0){
    res=res<<1;
    res = res|(number & 1);
    number=number>>1;
  }
  return res;
}

int main() {
  int n ;
  scanf("%d",&n) ;
  int number ;
  for ( int i = 0 ; i < n ; i ++ ){
    scanf("%d",&number ) ;
    if ( number % 2 )
      printf("%d\n",number ) ;
    else {
      printf("%d\n",rotate_binary(number) ) ;
    }
  }
  return 0 ;
}
  
