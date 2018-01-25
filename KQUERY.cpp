#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;

typedef pair<int,int> ii ;

ii input_arr[30010] ;
int n , nq , seg[120010] , ans[200010] ;

struct queries {
  int k , l , r , queryno ;
} q[200010] ;


bool custom_sort ( queries a , queries b ){
  return a.k < b.k ;
}

bool custom_sort2 ( ii a , ii b ){
  return a.second < b.second ;
}

int query ( int vertex , int lseg , int rseg , int lquery , int rquery , int k ){
  if ( lseg > rquery || rseg < lquery )
    return 0 ;

  if ( lseg >= lquery && rseg <= rquery )
    return seg[vertex] ;

  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  
  return query ( lchild , lseg , mid , lquery , rquery , k ) + query ( lchild + 1 , mid + 1 , rseg , lquery , rquery , k ) ;
}

void update ( int vertex , int lseg , int rseg , int index ){
  if ( lseg > index || rseg < index )
    return ;
  if ( lseg == index && rseg == index ){
    seg[vertex] ++ ;
    return ;
  }
  int lchild = vertex<<1 , mid = (lseg+rseg)>>1 ;
  update ( lchild , lseg , mid , index ) ;
  update ( lchild + 1 , mid + 1 , rseg , index ) ;
  seg[vertex] = seg[lchild] + seg[lchild + 1] ;
}

int main() {
 
  scanf("%d" , &n ) ;
  for ( int i = 1 ; i <= n ; i ++ ){
    input_arr[i].first = i ;
    scanf("%d" , &input_arr[i].second ) ;
  }

  sort ( input_arr + 1 , input_arr + n + 1 , custom_sort2 ) ;
    
  scanf("%d" , &nq ) ;

  for ( int i = 0 ; i < nq ; i ++ ){
    scanf("%d%d%d", &q[i].l , &q[i].r , &q[i].k ) ;
    q[i].queryno = i ;
  }

  sort ( q , q + nq , custom_sort) ;

  int j = n ;
  for ( int i = nq - 1 ; i >= 0 ; i -- ){
    while ( j > 0 && input_arr[j].second > q[i].k ){
      update ( 1 , 1 , n , input_arr[j].first ) ;
      j -- ;
    }
    ans[q[i].queryno] = query ( 1 , 1 , n , q[i].l , q[i].r , q[i].k ) ;
  }

  for ( int i = 0 ; i < nq ; i ++ )
    printf("%d\n" , ans[i] ) ;
  return 0 ;
}
