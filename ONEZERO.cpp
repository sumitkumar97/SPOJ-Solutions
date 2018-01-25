#include <iostream>
#include <cstdio>
#include <queue>
using namespace std ;

int l = 1 , r = 2 , tree[10000010] , arr[5000000] ;

void build_tree ( int vertex , int child ){
  if  ( vertex > 10000000 )
    return ; 
  if ( child == 1 )
    tree[vertex] = 0 ;
  else
    tree[vertex] = 1 ;
  build_tree( vertex<<1 , l ) ;
  build_tree ( (vertex<<1) + 1 , r ) ;
}


int main() {
  int test , n ;
  scanf("%d" , &test ) ;
  build_tree ( 1 , 2 ) ;
  while ( test -- ){
    queue<pair<int , int > > myqueue ;
    scanf("%d" , &n ) ;
    myqueue.push ( make_pair ( 1 , 0 ) ) ;
    int ans ;
    while ( !myqueue.empty() ){
      ans = myqueue.front().second ;
      ans = (ans*10) + tree[myqueue.front().first] ;
      ans = ans % n ;
      if ( !ans )
	break ;
      myqueue.push ( make_pair ( myqueue.front().first << 1  , ans )) ;
      myqueue.push ( make_pair ( (myqueue.front().first<<1) + 1 , ans ) ) ;
      myqueue.pop();
    }
    int x = myqueue.front().first  ; //tree[myqueue.front().first] will store the last digit of the desired answer
    int count = 0 ;
    while ( x > 0 ) { // moving up the tree towards the root 
      arr[count] = tree[x] ;
      count ++ ;
      x >>= 1 ;
    }
    for ( int i = count - 1 ; i >= 0 ; i -- )
      printf("%d" , arr[i] ) ;
    printf("\n") ;
  }
  return 0 ;
}
    
