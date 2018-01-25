#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

int main() {
  int test ;
  scanf("%d",&test) ;
  char a[10] ;
  int first[10] = { 2 , 2 , -2 , -2 , 1 , -1 , 1  ,-1 } ;
  int second[10] = { 1 , -1 , 1 , -1 , 2 , 2 , -2 , -2 } ;
  int x1 , y1 , x2 , y2 ;
  while ( test -- ){
    queue < pair < ii , int >  > myqueue ;
    bool pushed[10][10] = {false} ;
    scanf("%s",a) ;
    x1 = a[0] - 'a' + 1 ;
    y1 = a[1] - '0' ;
    scanf("%s",a) ;
    x2 = a[0] - 'a'+ 1 ;
    y2 = a[1] - '0' ;
    myqueue.push ( make_pair (make_pair ( x1 , y1 ) , 0 ) ) ;
    pushed[x1][y1] = true ;
    int x , y , dist ;
    while ( !myqueue.empty() ){
      x = myqueue.front().first.first ;
      y = myqueue.front().first.second ;
      dist = myqueue.front().second ;
      if ( x == x2 && y == y2 )
	break ;
      myqueue.pop() ;
      for ( int i = 0 ; i < 8 ; i ++ ){
	x += first[i] ;
	y += second[i] ;
	if ( x > 0 && x <= 8 && y > 0 && y <= 8 )
	  if ( !pushed [x][y] ){
	    myqueue.push ( make_pair ( make_pair ( x , y ) , dist + 1 ) ) ;
	    pushed[x][y] = true ;
	  }
	x -= first[i] ;
	y -= second[i] ;
      }
    }
    printf("%d\n",myqueue.front().second) ;
  }
  return 0 ;
}
