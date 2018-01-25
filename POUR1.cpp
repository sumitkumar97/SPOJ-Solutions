#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <queue>
using namespace std ;

typedef pair<int,int> ii ;
int a , b , c ;
map<ii , bool > pushed ;

int bfs ( queue<pair<ii , int> > &myqueue , pair<ii , int > vertex ){
  if ( vertex.first.first == c || vertex.first.second == c )
    return vertex.second ;
  if ( pushed.find(make_pair( a , vertex.first.second)) == pushed.end() ){
    pushed[ make_pair ( a , vertex.first.second ) ] = true ;
    myqueue.push (make_pair ( make_pair ( a , vertex.first.second ) , vertex.second+1 ) ) ;
    //    cout<<"pushed\t" <<a<<" "<<vertex.first.second<<endl ;
  }
  if ( pushed.find( make_pair ( 0 , vertex.first.second ) ) == pushed.end() ){
    pushed[ make_pair ( 0 ,vertex.first.second ) ] = true ;
    myqueue.push (make_pair (  make_pair ( 0 , vertex.first.second ) ,  vertex.second + 1 ) );
    //    cout<<"pushed\t" <<"0"<<" "<<vertex.first.second<<endl ;
  }
  if ( pushed.find ( make_pair ( vertex.first.first , 0 ) ) == pushed.end() ){
    pushed[ make_pair ( vertex.first.first , 0 )] = true ;
    myqueue.push ( make_pair ( make_pair ( vertex.first.first , 0 ) , vertex.second + 1 ) ) ;
    //    cout<<"pushed\t" <<vertex.first.first<<" "<<"0"<<endl ;
  }
  if ( pushed.find ( make_pair ( vertex.first.first , b ) ) == pushed.end() ) {
    pushed [ make_pair ( vertex.first.first , b ) ] = true ;
    myqueue.push ( make_pair ( make_pair ( vertex.first.first , b ) , vertex.second + 1 ) ) ;
    //    cout<<"pushed\t" <<vertex.first.first<<" "<<b<<endl ;
  }
  int x , y ;
  x = ( vertex.first.first + vertex.first.second ) ;
  if ( x > a )
    x = a ;
  y = vertex.first.second - ( x - vertex.first.first ) ;

  if ( pushed.find ( make_pair ( x , y ) ) == pushed.end() ){
    pushed [ make_pair ( x , y ) ] = true ;
    myqueue.push ( make_pair ( make_pair ( x , y ) , vertex.second + 1 )) ;
    //    cout<<"pushed\t" <<x<<" "<<y<<endl ;
  }

  y = ( vertex.first.first + vertex.first.second ) ;
  if ( y > b )
    y = b ;
  x = vertex.first.first - ( y - vertex.first.second ) ;
  if ( pushed.find ( make_pair ( x , y ) ) == pushed.end() ){
    pushed [ make_pair ( x , y ) ] = true ;
    myqueue.push ( make_pair ( make_pair ( x , y ) , vertex.second + 1 )) ;
    //    cout<<"pushed\t" <<x<<" "<<y<<endl ;
  }
  return 0 ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test -- ){
    scanf("%d%d%d",&a,&b,&c) ;
    queue<pair<ii , int> > myqueue ;
    myqueue.push(make_pair(make_pair(0,0), 0)) ;
    pushed[make_pair(0,0)] = true ;
    int ans = 0 ;
    while ( !myqueue.empty()) {
      ans = bfs ( myqueue , myqueue.front() ) ;
      if ( ans )
	break ;
      myqueue.pop() ;
    }
    if ( ans )
      printf("%d\n" , ans ) ;
    else
      printf("-1\n" ) ;
    pushed.clear() ;
  }
  return 0 ;
}


    
