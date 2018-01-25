#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int test , arr[1000010] , n ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    int count[10] = {0} ;
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ )
      scanf("%d" , &arr[i] ) ;

    int flag = -1 ;
    
    for ( int i = n-1 ; i >= 0 ; i -- ){
      count[arr[i]] ++ ;
      for ( int j = arr[i]+1 ; j < 10 ; j ++ ){
	if ( count[j] > 0 ){
	  count[j] -- ;
	  arr[i] = j ;
	  flag = i ;
	  break ;
	}
      }
      if ( flag != -1 )
	break ;
    }

    if ( flag != -1  ){
      for ( int i = 0 ; i <= flag ; i ++ )
	printf("%d" , arr[i] ) ;
      for ( int i = 0 ; i <= 9 ; i ++ ){
	while ( count[i] -- )
	  printf("%d" , i ) ;
      }
      printf("\n") ;
    }
    else
      printf("-1\n") ;
  }
  return 0 ;
}
	
