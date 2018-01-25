#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std ;

typedef pair<int , pair<int,int> > edge ;

int price , no_of_vertices , no_of_edges , mst_length ;
edge edgelist[300010] ;

bool custom_sort ( edge a , edge b ){
  return a.first < b.first ;
}

struct node {
  int info , rank ;
  struct node *next ;
}first[1010] ;

int find ( int vertex ) {
  struct node *temp ;
  int root ;
  temp = first[vertex].next ;
  root = vertex ;
  while ( temp != NULL ){
    root = temp->info ;
    temp = temp->next ;
  }
  //path compression
  struct node *set , *tobeset ;
  set = &first[root] ;
  temp = first[vertex].next ;
  while ( temp != NULL ){
    tobeset = temp ;
    temp = temp->next ;
    tobeset = set ;
  }
  return root ;
}
  
bool unionfind ( int vertex1 , int vertex2 ) {
  int root1 = find(vertex1) , root2 = find(vertex2) ;
  struct node *minrank , *maxrank ;
  //  cout<<vertex1<<" "<<vertex2<<endl ;
  //  cout<<"Find(vertex1) = "<<root1<<" Find(vertex2) = "<<root2<<endl ;
  if ( root1 != root2 ){
    if ( first[root1].rank < first[root2].rank ){
      minrank = &first[root1] ;
      maxrank = &first[root2] ;
    }
    else {
      minrank = &first[root2] ;
      maxrank = &first[root1] ;
    }
    minrank->next = maxrank ;
    maxrank->rank += minrank->rank ;
    return true ;
  }
  else
    return false ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  while ( test -- ) {
    mst_length = 0 ;
    scanf("%d",&price ) ;
    scanf("%d",&no_of_vertices ) ;
    scanf("%d",&no_of_edges ) ;
    for ( int i = 0 ; i < no_of_edges ; i ++ )
      scanf("%d%d%d", &edgelist[i].second.first , &edgelist[i].second.second ,&edgelist[i].first ) ;
    sort ( edgelist , edgelist + no_of_edges , custom_sort ) ;
    for ( int i = 1 ; i <= no_of_vertices ; i ++ ) {
      first[i].next = NULL ;
      first[i].info = i ;
      first[i].rank = 1 ;
    }
    for ( int i = 0 ; i < no_of_edges ; i ++ ) {
      if ( unionfind(edgelist[i].second.first , edgelist[i].second.second ) ){
	//        cout<<"weight = "<<edgelist[i].first<<endl ;
	mst_length += edgelist[i].first ;
      }
    }
    printf("%d\n",mst_length*price) ;
  }
  return 0 ;
}
