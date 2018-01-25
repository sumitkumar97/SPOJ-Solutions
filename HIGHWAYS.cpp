#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std ;

typedef pair<int,int> ii ;
int source , destination , n , visited[100010] ;
vector<ii> adjlist[100010] ;

class Compare {
public :
  bool operator()( ii a , ii b ){
    return b.second < a.second ;
  }
} ;

void dijkstra (){
  priority_queue<ii , vector<ii> , Compare > myqueue ;
  myqueue.push ( make_pair ( source , 0 ) ) ;
  visited[source] = 0 ;
  while ( !myqueue.empty() ){
    /*    for ( int i = 1 ; i <= n ; i ++ )
      printf("%d " , visited[i] ) ;
      printf("\n") ; */
    if ( myqueue.top().first == destination )
      break ;
    for ( int i = 0 ; i < adjlist[myqueue.top().first].size() ; i ++ ){
      if ( myqueue.top().second + adjlist[myqueue.top().first][i].second < visited[adjlist[myqueue.top().first][i].first] ){
	visited[adjlist[myqueue.top().first][i].first] = myqueue.top().second + adjlist[myqueue.top().first][i].second ;
	myqueue.push ( make_pair ( adjlist[myqueue.top().first][i].first , visited[adjlist[myqueue.top().first][i].first] ) ) ;
      }
    }
    myqueue.pop() ;
  }
}

int main() {
  int test , m , u , v , time ;
  scanf("%d" , &test ) ;
  while ( test -- ){
    scanf("%d%d" , &n , &m ) ;
    scanf("%d%d" , &source , &destination ) ;
    for ( int i = 1 ; i <= n ; i ++ )
      visited[i] = 2000000000 ;
    for ( int i = 0 ; i < m ; i ++ ){
      scanf("%d%d%d" , &u , &v , &time ) ;
      adjlist[u].push_back(make_pair ( v , time ) ) ;
      adjlist[v].push_back ( make_pair ( u , time ) ) ;
    }
    dijkstra() ;
    if ( visited[destination] != 2000000000 )
      printf("%d\n" , visited[destination] ) ;
    else
      printf("NONE\n") ;
    for ( int i = 0 ; i <= n ; i ++ )
      adjlist[i].clear() ;
  }
  return 0 ;
}
			   
      
    
    
  
