#include <iostream>
#include <cstdio>
#define MAX 2000000000 ;
using namespace std ;

int n , arr[30010] , seg[120010] , lazy[120010] ;

void seg_build ( int vertex , int lseg , int rseg ){

  if ( lseg == rseg ){
    seg[vertex] = arr[lseg] ;
    return ;
  }

  int mid = (lseg+rseg)>>1 ;
  seg_build ( vertex<<1 , lseg , mid ) ;
  seg_build ( (vertex<<1) + 1 , mid + 1 , rseg ) ;

  seg[vertex] = min (seg[vertex<<1] , seg[(vertex<<1) + 1] ) ;

}

void update ( int vertex , int lseg , int rseg , int lquery , int rquery , int v ){

  if ( lazy[vertex] ){
    seg[vertex] += lazy[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex<<1] += lazy[vertex] ;
      lazy[(vertex<<1) + 1] += lazy[vertex] ;
    }
    lazy[vertex] = 0 ;
  }

  if ( lquery > rseg || rquery < lseg )
    return ;
  if ( lseg >= lquery && rseg <= rquery ){
    seg[vertex] += v ;
    if ( lseg != rseg ){
      lazy[vertex<<1] += v ;
      lazy[(vertex<<1) + 1] += v ;
    }
    return ;
  }

  int mid = ( lseg+rseg )>>1 ;
  update ( vertex<<1 , lseg , mid , lquery , rquery , v ) ;
  update ( (vertex<<1) + 1 , mid + 1 , rseg , lquery , rquery , v ) ;
  seg[vertex] = min ( seg[vertex<<1] , seg[(vertex<<1) + 1] ) ;

}

int query ( int vertex , int lseg  , int rseg , int lquery , int rquery ){

  if ( lquery > rseg || rquery < lseg )
    return MAX ;

  if ( lazy[vertex] ){
    seg[vertex] += lazy[vertex] ;
    if ( lseg != rseg ){
      lazy[vertex<<1] += lazy[vertex] ;
      lazy[(vertex<<1) + 1] += lazy[vertex] ;
    }
    lazy[vertex] = 0 ;
  }

  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex] ;

  int mid = (lseg+rseg)>>1 ;
  int p1 = query ( vertex<<1 , lseg , mid , lquery , rquery ) ;
  int p2 = query ( (vertex<<1) + 1 , mid + 1 , rseg , lquery , rquery ) ;

  return min ( p1 , p2 ) ;
}



char s[30010] ;

int main() {
  int m , k ;
  for ( int test = 1 ; test < 11 ; test ++ ){
    scanf("%d" , &n ) ;
    scanf("%s" , s ) ;

    for ( int i = 0 ; i <= (n<<2) ; i ++ )
      lazy[i] = 0 ;

    arr[0] = 0 ;
    for ( int i = 0 ; i < n ; i ++ )
      arr[i+1] = arr[i] + ( s[i] == '(' ? 1 : -1 ) ;

    seg_build ( 1 , 1 , n ) ;

    scanf("%d" , &m ) ;

    printf("Test %d:\n" , test ) ;

    for ( int i = 0 ; i < m ; i ++ ){
      scanf("%d" , &k ) ;

      if ( !k ){

	if ( query ( 1 , 1 , n , 1 , n ) >= 0 && query ( 1 , 1 , n , n , n ) == 0 )
	  printf("YES\n") ;
	else
	  printf("NO\n") ;
      }
      else {
	update ( 1 , 1 , n , k , n , ( s[k-1] == '(' ? -2 : 2 ) ) ;
	if (s[k-1] == '(' ) s[k-1] = ')' ;
	else s[k-1] = '(' ;
	//printf("%s" , s ) ;
      }
    }
  }
  return 0 ;
}
    
