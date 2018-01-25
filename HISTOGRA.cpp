#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>
using namespace std;

int main() {
  long long n , ans , temp , area , i , count ;
  scanf("%lld",&n) ;
  stack<pair<long long int , int > > mystack ;
  pair<long long int , int > t ;
  while ( n ) {
    scanf("%lld",&temp) ;
    ans = temp ;
    mystack.push(make_pair(temp,1)) ;
    for ( i = 1 ; i < n ; i ++ ) {
      scanf("%lld", &temp ) ;
      if ( temp > mystack.top().first ) {
	mystack.push(make_pair(temp,1)) ;
      }
      else if ( mystack.top().first == temp ) {
	t = mystack.top() ;
	mystack.pop() ;
	mystack.push(make_pair(t.first , t.second + 1 ) ) ;
      }
      else {
	count = 0 ;
	while ( !mystack.empty() && mystack.top().first > temp ){
	  t = mystack.top() ;
	  count += t.second ;
	  area = t.first*count ;
	  if ( area > ans )
	    ans = area ;
	  mystack.pop() ;
	}
	mystack.push(make_pair(temp , count + 1) );
      }
    }
    count = 0 ;
    while ( !mystack.empty() ){
      t = mystack.top() ;
      count += t.second ;
      area = t.first*count ;
      if ( area > ans )
	ans = area ;
      mystack.pop() ;
    }
    printf("%lld\n",ans) ;
    scanf("%lld",&n) ;
  }
  return 0 ;
}
