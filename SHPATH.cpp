#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#include <map>
#include <queue>
using namespace std ;

typedef pair<int,int> ii ;
vector <ii> adjlist[10010] ;

class Compare
{
public:
  bool operator() (ii a , ii b )
  {
    return b.second < a.second ;
  }
};

ii front ;
int dist[10010] , no_of_cities ;

int shortest_path ( int source , int destination ) {
  priority_queue<ii , vector<ii> , Compare > pq ;
  for ( int i = 1 ; i <=  no_of_cities ; i ++ )
    dist[i] = 1000000000 ;
  pq.push(make_pair(source , 0) ) ;
  dist[source] = 0 ;
  while ( !pq.empty() ){
    front = pq.top() ;
    if ( front.first == destination )
      return front.second ;
    pq.pop() ;
    if ( front.second == dist[front.first] ){
      vector<pair<int,int> > ::iterator it ;
      for ( it = adjlist[front.first].begin() ; it != adjlist[front.first].end() ; it++ ){
	if ( dist[front.first] + it->second < dist[it->first] ){
	  pq.push(make_pair( it->first , dist[front.first] + it->second)) ;
	  dist[it->first] = dist[front.first] + it->second ;
	  //cout<<"dist["<<it->first<<"] = "<<dist[it->first]<<endl ;
	}
      }
    }
  }
  return dist[destination] ;
}

int main() {
  int test , no_of_adjcities[10010] , no_of_queries ;
  char city[10010][12] ;
  map <string , int> mymap ;
  int otherend , weight ;
  pair<int,int> queries[110] ;
  char source[12] , destination[12] ;
  scanf("%d",&test) ;
  while ( test -- ) {
    scanf("%d",&no_of_cities) ;
    for ( int i = 1 ; i <= no_of_cities ; i++ ) {
      adjlist[i].clear() ;
      scanf("%s",city[i]) ;
      mymap[city[i]] = i ;
      scanf("%d",&no_of_adjcities[i]) ;
      for ( int j = 1 ; j <= no_of_adjcities[i] ; j ++ ){
	scanf("%d%d", &otherend ,&weight ) ;
	adjlist[i].push_back( make_pair(otherend , weight) ) ;
      }
    }
    scanf("%d",&no_of_queries) ;
    for ( int i = 1 ; i <= no_of_queries ; i ++ ){
      scanf("%s%s",source , destination) ;
      queries[i].first = mymap[source] ;
      queries[i].second = mymap[destination] ;
      printf("%d\n",shortest_path(queries[i].first , queries[i].second ) ) ;
    }
  }
  return 0 ;
}

	
      
      
