#include <iostream>
#include <cstdio>
using namespace std ;

int test , n , a[100010] , count[1000010] , pos[1000010] , tree[100010] , occupied[100010] ;

int read ( int idx ){
  int sum = 0 ;
  while ( idx > 0 ){
    sum += tree[idx] ;
    idx -= ( idx & -idx ) ;
  }
  return sum ;
}

void update ( int idx , int val ){
  while ( idx < 100010 ){
    tree[idx] += val ;
    idx += ( idx & -idx ) ;
  }
}

int main() {
  scanf("%d" , &test ) ;
  while ( test -- ){
    for ( int i = 0 ; i < 1000010 ; i ++ )
      count[i] = 0 ;
    for ( int i = 0 ; i < 100010 ; i ++ ){
      occupied[i] = 0 ;
      tree[i] = 0 ;
    }
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d" , &a[i] ) ;
      count[a[i]] ++ ;
    }
    int x = 0 ;
    for ( int i = 0 ; i < 1000010 ; i ++ ){
      bool firstpos = true ;
      while ( count[i] -- ){
	if ( firstpos ){
	  pos[i] = x ;
	  firstpos = false ;
	}
	x ++ ;
      }
    }
    int ans = 0 ;
    occupied[pos[a[0]]] = 1 ;
    update ( pos[ a[0] ] + 1 , 1 ) ;
    for ( int i = 1 ; i < n ; i ++ ){
      int y = pos[a[i]] ;
      while ( occupied[y] )
	y ++ ;
      ans += i - read ( y + 1 ) ;
      occupied[y] = 1 ;
      update ( y + 1  , 1 ) ;
    }
    printf("%d\n" , ans ) ;
  }
  return 0 ;
}
