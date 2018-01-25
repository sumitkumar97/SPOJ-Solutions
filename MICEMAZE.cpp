#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#define MAX 2000000000
using namespace std ;

typedef long long ll ;

int main() {
  int cells , exitcell  , timer ;
  scanf("%d%d%d",&cells , &exitcell  , &timer ) ;
  vector<pair<int,ll> > adjlist[110] ;

  int no_of_edges , e1, e2 ;
  ll weight ;
  scanf("%d",&no_of_edges ) ;
  for ( int i = 0 ; i < no_of_edges ; i ++ ){
    scanf("%d%d%lld",&e1, &e2 , &weight ) ;
    adjlist[e2].push_back(make_pair ( e1 , weight )) ;
  }
  queue<int> myqueue ;
  long long reachingtime[110] ;
  for ( int i = 0 ; i < 110 ; i ++ )
    reachingtime[i] = MAX ;
  int count = 0 ;
  myqueue.push(exitcell) ;
  reachingtime[exitcell] = 0 ;
  while ( !myqueue.empty() ){
    int curr = myqueue.front() ;
    for ( int i = 0 ; i < adjlist[curr].size() ; i ++ ){
      if ( reachingtime[curr] + adjlist[curr][i].second <= reachingtime[adjlist[curr][i].first] ){
	//cout<<adjlist[curr][i].first<<endl ;
	reachingtime[adjlist[curr][i].first] = reachingtime[curr] + adjlist[curr][i].second ;
	myqueue.push ( adjlist[curr][i].first ) ;
      }
    }
    myqueue.pop() ;
  }
  for ( int i = 1 ; i <= cells ; i ++ )
    if ( reachingtime[i] <= timer )
      count ++ ;
  printf("%d",count) ;
  return 0 ;
}


  
