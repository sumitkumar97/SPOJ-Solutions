#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int x[] = { -1 , -1 , -1 , 0 , 0 , 1 , 1 , 1 } ;
int y[] = { -1 , 0 , 1 , -1 , 1 , -1 , 0 , 1 } ;

char g[110][110] ;
int  r , c ;

char pattern[] = "ALLIZZWELL" ;
bool ans , visited[110][110] ;

void dfs ( int a , int b , int iter){  // check the neighbours of a,b for next iterations

  if ( iter == strlen(pattern) ){
    ans = true ;
    return ;
  }

  visited[a][b] = true ;
  
  for ( int i = 0 ; i < 8 ; i ++ ){
    if ( a + x[i] >= 0 && a + x[i] < r && b + y[i] >= 0 && b + y[i] < c && !ans && !visited[ a + x[i]][ b + y[i]] && g[ a + x[i]][ b + y[i]] == pattern[iter] ){
      dfs ( a + x[i] , b + y[i]  , iter + 1 ) ;
    }
  }
  visited[a][b] = false ;
}

int main() {
  int test ;

  scanf("%d" , &test ) ;
  while ( test -- ){
    ans = false ;
    scanf("%d%d" , &r , &c ) ;
    for ( int i = 0 ; i < r ; i ++ ){
      scanf("%s" , g[i] ) ;
      for ( int j = 0 ; j < c ; j ++ )
	visited[i][j] = false ;
    }
    for ( int i = 0 ; i < r ; i ++ ){
      if ( ans )
	break ;
      for ( int j = 0 ; j < c ; j ++ ){
	if ( ans )
	  break ;
	if ( g[i][j] == 'A' )
	  dfs ( i , j , 1 ) ;
      }
    }
    if ( ans )
      printf("YES\n") ;
    else
      printf("NO\n") ;
  }
  return 0 ;
}
      
