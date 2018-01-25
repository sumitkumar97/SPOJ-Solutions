#include <iostream>
#include <cmath>
using namespace std ;

int egcd ( int a , int b ) {
  return b ? egcd ( b , a%b ) : a ;
}

int main() {
  ios_base::sync_with_stdio(false) ;
  cin.tie(nullptr) ;
  int test ;
  cin >> test ;
  int a , b , count = 0 ;
  while ( test -- ) {
    count = 0 ;
    cin >> a >> b ;
    int gcd = egcd(a,b);
    int sqt = (int)sqrt(gcd);
    for(int i = 1 ; i <= sqt; i++){
      if(gcd % i == 0){
	count += 2 ;
	if(i == gcd/i) count--;
      }
    }
    cout<<count<<"\n" ;
  }
  return 0 ;
}
