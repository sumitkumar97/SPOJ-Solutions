#include <iostream>
#include <cmath>
using namespace std ;

int main() {
  ios_base::sync_with_stdio(false) ;
  int test ;
  cin>>test ;
  long long n , first , second ;
  while ( test -- ) {
    cin>>n ;
    first = sqrt(n) ;
    second = 0 ;
    while ( first > 0 ) {
      if ( second*second > n ){
	cout<<"No\n" ;
	break ;
      }
      else if ( (first*first) + (second*second) == n ) {
	cout<<"Yes\n" ;
	break ;
      }
      else if ( (first*first) + (second*second) < n )
	second++ ;
      else
	first-- ;
    }
  }
  return 0  ;
}
