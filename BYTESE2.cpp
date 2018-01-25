#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std ;

typedef pair<int,int> ii ;

typedef vector<ii> vii ;


bool custom_sort ( ii a , ii b ){
  return a.first < b.first ;
}

int main() {
  int test ;
  scanf("%d",&test) ;
  vii entry ;
  while ( test -- ){
    int in ,out , n ;
    scanf("%d",&n) ;
    for ( int i = 0 ; i < n ; i ++ ){
      scanf("%d%d",&in,&out) ;
      entry.push_back ( make_pair( in , out ) )  ;
    }
    sort ( entry.begin() , entry.end() , custom_sort ) ;
    /*    for ( vii::iterator it = entry.begin() ; it != entry.end() ; it ++ )
	  cout<<it->first<<endl ; */
    int count = 0 , ans = 0 ;
    for ( int i = 0 ; i < entry.size() ; i ++ ){
      count = i + 1 ;
      for ( int j = i ; j >= 0 ; j -- )
	if ( entry[j].second <= entry[i].first )
	  count -- ;
      ans = max ( count , ans ) ;
    }
    printf("%d\n",ans) ;
    entry.clear() ;
  }
  return 0 ;
}
