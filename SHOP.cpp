#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
using namespace std ;

typedef pair< pair<int,int> , int > iii ;

int dist[30][30] , w , h , sx , sy , dx , dy , x[] = { 0 , 1 , 0 , -1 } , y[] = { -1 , 0 , 1 , 0 } ;
char shop[30][30] , temp[30][30] ;

class COMPARE {
public :
  bool operator()( iii a ,  iii b ){
    return a.second > b.second ;
  }
} ;

int sd (){
  dist[sx][sy] = 0 ;
  priority_queue <iii , vector<iii > , COMPARE > pq ;

  pq.push ( make_pair ( make_pair ( sx , sy ) , dist[sx][sy] ) ) ;

  while ( !pq.empty() ){

    iii t = pq.top() ;

    if ( t.first.first == dx && t.first.second == dy )
      return t.second ;
    for ( int i = 0 ; i < 4 ; i ++ ){
      if ( t.first.first + x[i] >= 0 && t.first.first + x[i] < w && t.first.second + y[i] >= 0 && t.first.second + y[i] < h && shop[t.first.first+x[i]][t.first.second+y[i]] != 'X' && shop[t.first.first+x[i]][t.first.second+y[i]] != 'S'){
	if ( shop[ t.first.first + x[i] ][t.first.second + y[i] ] == 'D' && t.second < dist[dx][dy] ){
	  dist[dx][dy] = t.second ;
	  pq.push ( make_pair ( make_pair ( dx , dy ) , dist[dx][dy] ) ) ;

	}
	else if ( t.second + shop[t.first.first+ x[i] ][ t.first.second + y[i] ] - '0' < dist[t.first.first+ x[i] ][ t.first.second + y[i] ]){
	  dist[t.first.first+ x[i] ][ t.first.second + y[i] ] = t.second + shop[t.first.first+ x[i] ][ t.first.second + y[i] ] - '0' ;
	  pq.push ( make_pair ( make_pair ( t.first.first + x[i] , t.first.second + y[i] ) , dist[t.first.first + x[i] ][ t.first.second + y[i] ] ) ) ;
	}
      }
    }
    pq.pop() ;
  }

  return dist[dx][dy] ;
}

int main() {

  scanf("%d%d" , &w , &h ) ;
  while ( w && h ){

    for ( int i = 0 ; i < h ; i ++ )
      scanf("%s" , temp[i]) ;
    for ( int i = 0 ; i < w ; i ++ ){
      for ( int j = 0 ; j < h ; j ++ ){
	shop[i][j] = temp[j][i] ;
	dist[i][j] = 2000000000 ;
	if ( shop[i][j] == 'S' ){
	  sx = i ;
	  sy = j ;
	}
	if ( shop[i][j] == 'D' ){
	  dx = i ;
	  dy = j ;
	}
      }
    }
    printf("%d\n" , sd() ) ;
    scanf("%d%d" , &w , &h ) ;
  }
  return 0 ;
}
