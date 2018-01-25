#include <iostream>
#include <cstdio>
using namespace std ;

int bit[1030][1030] , arr[1030][1030] , n ;

int read ( int x , int y ){
  int y1 , sum = 0 ;
  while ( x ){
    y1 = y ;
    while ( y1 ){
      sum += bit[x][y1] ;
      y1 -= y1 & -y1 ;
    }
    x -= x & -x ;
  }
  //  printf("sum = %d\n" , sum ) ;
  return sum ;
}

void update ( int x , int y , int val ){
  int y1 , x1 ;
  x1 = x ;
  while ( x1 <= n ){
    y1 = y ;
    while ( y1 <= n ){
      bit[x1][y1] += val - arr[x][y] ;
      y1 += y1 & -y1 ;
    }
    x1 += x1 & -x1 ;
  }
}
      

int main() {
  int test ;
  char query[10] ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i <= n ; i ++ )
      for ( int j = 0 ; j <= n ; j ++ ){
	arr[i][j] = 0 ;
	bit[i][j] = 0 ;
      }
    scanf("%s" , query ) ;
    int x1 , y1 , x2 , y2 , num ;
    while ( query[1] != 'N' ){

      if ( query[1] == 'E' ){
	scanf("%d%d%d" , &x1 , &y1 , &num ) ;
	update ( x1 + 1  , y1 + 1 , num ) ;
	arr[x1+1][y1+1] = num ;
      }
      else {
	scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2 ) ;
	printf("%d\n" , read ( x2 + 1 , y2 + 1 ) - read ( x1 , y2 + 1 ) - read ( x2 + 1 , y1 ) + read ( x1 , y1 ) ) ;
      }

      scanf("%s" , query ) ;
    }
    printf("\n") ;
  }
  return 0 ;
}
