#include <iostream>
#include <queue>
#include <utility>
using namespace std ;

int main() {
  int test , src , dest ;
  cin>> test ;
  bool arr[10000] = {false}  ;
  int j ;
  for ( int i = 2 ; i <= 5000 ; i ++ ) {
    if ( !arr[i] ) {
      j = 2 ;
      while ( i*j < 10000 ) {
	arr[i*j] = true ;
	j++ ;
      }
    }
  }
  int ans , flag = 0 ;
  queue<pair <int , int > > myqueue ;
  while ( test -- ) {
    bool visited[10000]={false} ;
    flag = 0 ;
    cin>> src >> dest ;
    myqueue.push(make_pair(src,0)) ;
    while ( !myqueue.empty() ) {
      pair<int,int> ele ;
      ele = myqueue.front() ;
      myqueue.pop() ;
      visited[ele.first] = true ;
      if ( ele.first == dest ) {
	ans = ele.second ;
	flag = 1 ;
	break ;
      }
      int remainder = ele.first%1000 ;
      int digit = ele.first/1000 ;
      for ( int i = 1 ; i < 10 ; i++ ){
	if ( !arr[i*1000 + remainder] ) {
	  if ( i != digit && !visited[i*1000 + remainder]) {
	    myqueue.push(make_pair( i*1000 + remainder , ele.second+1 ) );
	  }
	}
      }
      int quotient = ele.first / 1000 ;
      digit = ele.first / 100 ;
      digit %= 10 ;
      remainder = ele.first % 100 ;
      for ( int i = 0 ; i < 10 ;i ++ ) {
	if ( !arr[quotient*1000 + (i*100) + remainder] ) {
	  if ( i != digit && !visited[quotient*1000 + (i*100) + remainder]) {
	    myqueue.push(make_pair ( quotient*1000 +(i*100)+ remainder , ele.second + 1 )) ;
	  }
	}
      }
      quotient = ele.first / 100 ;
      digit = ele.first % 100 ;
      digit /= 10 ;
      remainder = ele.first % 10 ;
      for ( int i = 0 ; i < 10 ;i ++ ) {
	if ( !arr[quotient*100 + ( i*10) + remainder] ) {
	  if ( i != digit && !visited[quotient*100 + ( i*10) + remainder] ) {
	    myqueue.push(make_pair ( quotient*100 + (i*10) + remainder , ele.second + 1 )) ;
	  }
	}
      }
      quotient = ele.first / 10 ;
      digit = ele.first % 10 ;
      for ( int i = 0 ; i < 10 ;i ++ ) {
	if ( !arr[quotient*10 + i] ) {
	  if ( i != digit && !visited[quotient*10 + i] ) {
	    myqueue.push(make_pair ( quotient*10 + i , ele.second + 1 )) ;
	  }
	}
      }
    }
    if ( flag )
      cout<<ans<<"\n" ;
    else
      cout<<"Impossible\n" ;
    while ( !myqueue.empty() )
      myqueue.pop() ;
  }
  return 0 ;
}


  
