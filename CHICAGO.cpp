#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std ;


typedef pair<int,double> id ;
typedef vector<id> vid ;

vid adjlist[110] ;

double prob[110] ;
int n ;

class COMPARE {
public :
  bool operator()( id a , id b ){
    return a.second < b.second ;
  }
} ;

double maxprob ( ){
  prob[1] = 1 ;
  priority_queue<id , vid , COMPARE> pq ;
  pq.push( make_pair ( 1 , prob[1] ) ) ;

  while ( !pq.empty() ){

    if ( pq.top().first == n )
      return pq.top().second ;
    
    for ( int i = 0 ; i < adjlist[ pq.top().first ].size() ; i ++ ){
      if ( pq.top().second * adjlist[ pq.top().first ][i].second > prob [ adjlist[ pq.top().first ][i].first ] ){
	prob [ adjlist[ pq.top().first ][i].first ] = pq.top().second * adjlist[ pq.top().first ][i].second ;
	pq.push ( make_pair ( adjlist[ pq.top().first ][i].first , prob [adjlist[ pq.top().first ][i].first] ) ) ;
      }
    }
    pq.pop() ;
  }

}
  

int main() {
  int m , u , v ;
  double w ;
  scanf("%d" , &n ) ;
  while ( n ){
    scanf("%d" , &m ) ;

    for ( int i = 0 ; i <= n ; i ++ ){
      adjlist[i].clear() ;
      prob[i] = 0 ;
    }

    for ( int i = 0 ; i < m ; i ++ ){
      scanf("%d%d%lf" , &u , &v , &w ) ;
      adjlist[u].push_back ( make_pair ( v , w/100 ) ) ;
      adjlist[v].push_back( make_pair ( u , w/100 ) ) ;
    }
    
    printf("%.6lf percent\n" , maxprob()*100 ) ;
    scanf("%d" , &n ) ;
  }
  return 0 ;
}
