#include <iostream>
#include <cstdio>
#include <utility>
using namespace std ;

int height , width ;

int x[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 } ;
int y[] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 } ;
char grid[60][60] ;
int memo[60][60] = {0} ;

int length( int row , int column , int len , int ascii ) {
  int newrow , newcolumn , returningvalue = len ;
  if ( memo[row][column] != 0 )
    return len + memo[row][column] ;
  for (int i = 0 ; i < 8 ; i ++ ) {
    newrow = row + x[i] ;
    newcolumn = column + y[i] ;
    if ( newrow > - 1 && newrow < height && newcolumn > -1 && newcolumn < width ) {
      if ( (int)grid[newrow][newcolumn] - ascii == 1 ) {
	returningvalue = max ( returningvalue , length ( newrow , newcolumn , len + 1 , ascii + 1 ) ) ;
      }
    }
  }
  memo[row][column] = returningvalue - len ;
  return returningvalue ;
}
      
int main() {
  scanf("%d%d",&height,&width) ;
  char temp[60] ;
  pair<int , int > a[2510] ;
  int  pointertoa , caseno = 1 ;
  while ( height != 0 && width != 0 ) {
    pointertoa = 0 ;
    for ( int i = 0 ; i < height ; i ++ ) {
      scanf("%s",temp) ;
      for ( int j = 0 ; j < width ; j++ )  {
	grid[i][j] = temp[j] ;
	if ( grid[i][j] == 'A' ) {
	  a[pointertoa] = make_pair(i,j) ;
	  pointertoa++ ;
	}
      }
    }
    if ( pointertoa == 0 ) {
      printf("Case %d: 0\n",caseno) ;
      scanf("%d%d",&height,&width) ;
      caseno ++ ;
      continue ;
    }
    int ans = 0 ;
    for ( int i = 0 ; i < pointertoa ; i ++ ) {
      if ( ans == 26 )
	break ;
      ans = max ( ans , length( a[i].first , a[i].second , 1 , 65 ) ) ;
    }
    printf("Case %d: %d\n",caseno,ans) ;
    scanf("%d%d",&height,&width) ;
    caseno ++ ;
    for ( int i = 0 ; i < 51 ; i ++ )
      for ( int j = 0 ; j < 51 ; j ++ )
	memo[i][j] = 0 ;
  }
  return 0 ;
}
	
    
