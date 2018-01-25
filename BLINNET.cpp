#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std ;

int n , p ;

typedef pair < pair<int,int> , unsigned int > ii_i ;

ii_i edge[1000010] ;

bool custom_sort ( ii_i a , ii_i b ){
  return b.second > a.second ;
}

struct node {
  int info , rank ;
  struct node* next ;
} vertex[10010] ;   // connected component ( disjoint set )

int find (int a ){

  struct node* temp ;
  struct node* temp2 ;
  struct node* b ;
  temp = &vertex[a] ;
  while ( temp != temp->next )
    temp = temp->next ;
  // path compression
  temp2 = &vertex[a] ;
  while ( temp2 != temp2->next ){
    b = temp2 ;
    temp2 = temp2->next ;
    b->next = temp ;
  }
  return temp->info ;
}

bool union_by_rank( int a , int b ){
  if ( a == b )
    return false ;
  if ( vertex[a].rank > vertex[b].rank ){
    vertex[b].next = &vertex[a] ;
    vertex[a].rank += vertex[b].rank ;
  }
  else {
    vertex[a].next = &vertex[b] ;
    vertex[b].rank += vertex[a].rank ;
  }
  return true ;
}


int main() {
  int test , u , v ;
  unsigned int cost , ans ;
  char s[20] ;
  scanf("%d" , &test ) ;
  while ( test -- ) {
    int x = 0 ;
    ans = 0 ;
    scanf("%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i ++ ){
      scanf("%s" , s ) ;
      scanf("%d" , &p ) ;
      for ( int j = 0 ; j < p ; j ++ ){
	scanf("%d%u" , &v , &cost ) ;
	edge[x] = make_pair ( make_pair(i,v) , cost ) ;
	x ++ ;
      }
    }
    sort ( edge , edge + x , custom_sort ) ;
    for ( int i = 1 ; i <= n ; i ++ ){
      vertex[i].next = &vertex[i] ;
      vertex[i].rank = 1 ;
      vertex[i].info = i ;
    }

    for ( int i = 0 ;  i < x ; i ++ ){
      u = edge[i].first.first ;
      v = edge[i].first.second ;
      cost = edge[i].second ;
      if ( union_by_rank ( find(u) , find(v) ) )
	ans += cost ;
    }
    printf("%u\n" , ans ) ;
  }
  return 0 ;
}
