#include <iostream>
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false) ;
  int test ;
  cin >> test ;
  int inputarray[1000010] , n ;
  while ( test -- ) {
    int count[1000010]={0} ;
    cin >> n ;
    if ( n == 0 ) {
      cout<<"NO\n" ;
      continue ;
    }

    for ( int i = 0 ; i < n ; i ++ ) {
      cin >> inputarray[i] ;
      count[inputarray[i] + 1000] ++ ;
    }
    int max_count = -1 ;
    int ans ;
    for (int i = 0 ; i < n ; i ++ ) {
      if ( count[inputarray[i]+1000] > max_count ) {
	max_count = count[inputarray[i] + 1000] ;
	ans = inputarray[i] ;
      }
    }
    if ( count[ans + 1000] > n/2 )
      cout<<"YES "<<ans<<"\n" ;
    else
      cout<<"NO\n" ;
  }
  return 0 ;
}
    
