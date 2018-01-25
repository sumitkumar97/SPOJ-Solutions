#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

queue<ii> myqueue ;

int f , s , g , u , d ;
bool visited[1000010] ;

void bfs ( int s , int presses ){
  if ( s + u <= f &&  !visited[s + u] ){
    visited[s+u] = true ;
    myqueue.push( make_pair ( s + u , presses + 1 ) ) ;
  }
  if ( s - d > 0 && !visited[s - d] ){
    visited[s-d] = true ;
    myqueue.push( make_pair ( s - d  , presses + 1 ) ) ;
  }
  myqueue.pop() ;
}

int main() {

  scanf("%d%d%d%d%d" , &f , &s , &g , &u , &d ) ;
  visited[s] = true ;
  myqueue.push ( make_pair ( s , 0 ) ) ;
  
  while ( !myqueue.empty() && myqueue.front().first != g )
    bfs ( myqueue.front().first , myqueue.front().second ) ;
  
  if ( !myqueue.empty() )
    printf("%d\n" , myqueue.front().second ) ;
  else
    printf("use the stairs\n") ;
  
  return 0 ;
}
