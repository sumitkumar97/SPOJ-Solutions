#include <iostream>
#include <algorithm>
using namespacestd ;

int main() {
  int test ;
  cin >> test ;
  int r_stamps , friends , ans , arr[1010] , sum ;
  for ( int k = 1 ; k <= test ; k ++ ) {
    cin >> r_stamps >> friends ;
    for( int i = 0 ; i < friends ; i ++ ) {
      cin >> arr[i] ;
    }
    sort ( arr , arr + friends ) ;
    sum = 0 , ans = 0 ;
    int j = friends - 1 ;
    while ( j >= 0 && sum < r_stamps ) {
      sum += arr[j] ;
      ans += 1 ;
      j-- ;
    }
    cout << "Scenario #"<<k<<":\n" ;
    if ( j < 0 && sum < r_stamps )
      cout << "impossible\n\n" ;
    else
      cout << ans << "\n\n" ;
  }
  return 0 ;
}
