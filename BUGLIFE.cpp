#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

const int male = 1 , female = 0 ;
int gender[2010] , suspicion ;
bool visited[2010] ;
queue<int> myqueue ;

void bfs(int root , vector<int> *adj ) {
  int x ;
  gender[root] = male ;
  myqueue.push(root) ;
  visited[root] = 1 ;
  while ( !myqueue.empty() ) {
    x = myqueue.front() ;
    myqueue.pop() ;
    for ( int i = 0 ; i < adj[x].size() ; i ++ ) {
      if ( !visited[adj[x][i]] ) {
	gender[adj[x][i]] = !gender[x] ;
	visited[adj[x][i]] = 1 ;
	myqueue.push(adj[x][i]) ;
      }
      else if ( gender[adj[x][i]] == gender[x] ){
	suspicion = 1 ;
	while ( !myqueue.empty() )
	  myqueue.pop() ;
	break ;
      }
    }
  }
}

int main() {
  int test  , v1 , v2 ;
  int bugs , interactions ;
  cin>>test ;
  for ( int k = 1 ; k <= test ; k ++ ) {
    cin >> bugs >> interactions ;
    vector<int> adj[bugs+10] ;
    for ( int j = 1 ; j <= bugs ; j++ )
      visited[j] = 0 ;
    suspicion = 0 ;
    for ( int j = 0 ; j < interactions ; j ++ ) {
      cin>>v1>>v2 ;
      adj[v1].push_back(v2) ;
      adj[v2].push_back(v1) ;
    }
    for ( int i = 1 ; i <= bugs  ; i ++ ) {
      if ( visited[i] == 0 )
	bfs(i,adj) ;
      if ( suspicion == 1 )
	break ;
    }
    cout<<"Scenario #"<<k<<":\n" ;
    if ( suspicion == 1 )
      cout<<"Suspicious bugs found!\n" ;
    else
      cout<<"No suspicious bugs found!\n" ;
  }
  return 0 ;
}




