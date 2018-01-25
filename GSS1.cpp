#include <iostream>
#include <cstdio>
using namespace std ;
int MIN = -2000000000 ;

int in[50010] , z ;
struct cont {
  int fullsum,maxsum,lsum,rsum ;
}seg[200010] , siqr[50010] ;

cont seg_build ( int vertex , int lseg , int rseg ){
  if ( lseg == rseg ) {
    seg[vertex].fullsum = seg[vertex].maxsum = seg[vertex].lsum = seg[vertex].rsum = in[lseg] ;
    return seg[vertex] ;
  }
  cont p1 = seg_build ( vertex<<1 , lseg , (lseg+rseg)>>1 ) ;
  cont p2 = seg_build ( (vertex<<1)+1 , ((lseg+rseg)>>1)+1 , rseg) ;
  seg[vertex].fullsum = p1.fullsum + p2.fullsum ;
  seg[vertex].maxsum = max ( max ( p1.maxsum , p2.maxsum ), p1.rsum + p2.lsum ) ;
  seg[vertex].lsum = max ( p1.lsum , p1.fullsum + p2.lsum ) ;
  seg[vertex].rsum = max ( p2.rsum , p2.fullsum + p1.rsum ) ;
  return seg[vertex] ;
}

void copier ( cont a ){
  siqr[z].maxsum = a.maxsum ;
  siqr[z].fullsum = a.fullsum ;
  siqr[z].lsum = a.lsum ;
  siqr[z].rsum = a.rsum ;
}

void query ( int vertex , int lseg , int rseg , int lquery , int rquery ){
  if ( lquery > rseg || rquery < lseg )
    return ;
  if ( lseg >= lquery && rseg <= rquery ) {
    copier ( seg[vertex] ) ;
    z ++ ;
    return ;
  }
  query ( vertex<<1 , lseg , (lseg+rseg)>>1 , lquery , rquery ) ;
  query ( (vertex<<1)+1 , ((lseg+rseg)>>1)+1 , rseg , lquery , rquery ) ;
}

int including_mid ( int l , int r , int mid ) {
  int sum = siqr[mid].rsum ;
  int t = sum ;
  for ( int i = mid + 1 ; i <= r ; i ++ ){
    if ( sum + siqr[i].lsum > t )
      t = sum + siqr[i].lsum ;
    sum += siqr[i].fullsum ;
  }
  int leftans = t ;
  sum = siqr[mid].lsum ;
  t = sum ;
  for ( int i = mid - 1 ; i >= l ; i -- ){
    if ( sum +siqr[i].rsum > t )
      t = sum + siqr[i].rsum ;
    sum += siqr[i].fullsum  ;
  }
  int rightans = t ;
  return max ( max ( leftans , rightans ) , max ( leftans + rightans - siqr[mid].lsum - siqr[mid].rsum +siqr[mid].fullsum , siqr[mid].maxsum ) ) ;
}

int ans ( int l , int r ){
  if ( l == r )
    return siqr[l].maxsum ;
  if ( l > r )
    return MIN ;
  int mid = ( l + r ) >> 1 ;
  int a = ans ( l , mid - 1 ) ;
  int b = including_mid ( l , r , mid ) ;
  int c = ans ( mid + 1 , r ) ;
  return max ( max ( a , b ) , c ) ;
}

int main() {
  int n , m ;
  scanf("%d", &n ) ;
  for ( int i = 1 ; i <= n ; i ++ )
    scanf("%d", &in[i] ) ;
  seg_build ( 1 , 1 , n ) ;
  scanf("%d", &m ) ;
  int x , y ;
  while ( m -- ){
    scanf("%d%d", &x , &y ) ;
    z = 0 ;
    query ( 1 , 1 , n , x , y ) ;
    int result = ans ( 0 , z - 1 ) ;
    printf("%d\n",result ) ;
  }
  return 0 ;
}
  
