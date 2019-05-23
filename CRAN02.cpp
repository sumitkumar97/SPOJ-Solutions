#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define sz size()
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int arr[1000010];
int cumsum[1000010];

int main() {
  int test , n ;
  map<ll,int> mymap;
  scanf("%d" , &test ) ;
  while ( test -- ) {
    scanf("%d" , &n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
      scanf("%d" , &arr[i] ) ;
      cumsum[i] = ( i > 0 ? cumsum[i-1] : 0 ) + arr[i];
    }
    ll ans = 0 ;
    mymap.clear();
    for ( int i = n -1 ; i >= 0 ; i -- ) { //i = leftmostpoint
      mymap[cumsum[i]] ++ ;
      ll key = cumsum[i] - arr[i];
      if ( mymap.find(key) != mymap.end() ) {
        ans += mymap[key];
      }
    }
    printf("%lld\n" , ans ) ;
  }
  return 0;
}
