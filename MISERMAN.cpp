#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
  int n , m ;
  int faretoreach[110][110] , faretonext[110][110] ; //faretoreach = totalfaretoreachnext
  scanf("%d%d",&n,&m) ;
  for ( int j = 0 ; j < m ; j ++ )
    scanf("%d",&faretoreach[0][j]) ;
  for ( int i = 1 ; i < n ; i ++ ){
    for ( int j = 0 ; j < m ; j ++ ) {
      scanf("%d",&faretonext[i][j] ) ;
      if ( j == 0 )
	faretoreach[i][j] = faretonext[i][j] + min ( faretoreach[i-1][j] , faretoreach[i-1][j+1] ) ;
      else if ( j == m-1 )
	faretoreach[i][j] = faretonext[i][j] + min ( faretoreach[i-1][j-1] , faretoreach[i-1][j] ) ;
      else
	faretoreach[i][j] = faretonext[i][j] + min ( faretoreach[i-1][j-1] , min ( faretoreach[i-1][j] , faretoreach[i-1][j+1] ) ) ;
    }
  }
  int min = 10010 ;
  for ( int j = 0 ; j < m ; j ++ )
    if ( faretoreach[n-1][j] < min )
      min = faretoreach[n-1][j] ;
  printf("%d",min) ;
  return 0 ;
}
