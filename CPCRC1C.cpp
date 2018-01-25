#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std ;

typedef long long ll ;

ll arr[20] ;

ll recsum ( int n , int done ){

  ll sum = 0 , zeroes = 1 ; //zeroes was int in last solution
  int no_of_digits = 0 , temp = n , ldigit = 0 ;
  while ( temp ){
    no_of_digits ++ ;
    ldigit = temp ;
    zeroes *= 10 ;
    temp /= 10 ;
  }
  zeroes /= 10 ;
  
  for ( int i = 0 ; i < ldigit ; i ++ )
    sum += ((done+i)*zeroes ) + arr[ no_of_digits - 1 ] ;

  if ( zeroes == 0 )
    sum += done ;
  
  if ( zeroes > 0  )
    sum += recsum ( n %(zeroes) , done + ldigit ) ;
  
  return sum ;
}

int main(){
  arr[0] = 0 ;
  ll tenpower ;
  for ( int i = 1 ; i <= 9 ; i ++ ){
    tenpower = 1 ;
    for ( int j = 1 ; j < i ; j ++ )
      tenpower *= 10 ;
    for ( int j = 0 ; j <= 9 ; j ++ ){
      arr[i] += (j*(tenpower)) + arr[i-1] ;
    }
  }
  int a , b ;
  scanf("%d%d" , &a , &b ) ;
  while ( a != -1 ){
    printf("%lld\n" , recsum ( b , 0 ) - (a>0? recsum ( a - 1 , 0 ):0) ) ;
    scanf("%d%d" , &a , &b ) ;
  }
  return 0 ;
}
