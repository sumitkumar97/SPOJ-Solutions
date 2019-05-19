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

bool arr[(int)1e6 + 10];

int main() {
  int test;
  scanf("%d", &test);
  ll l, u;
  while (test--) {
    scanf("%lld%lld", &l, &u);
    for (int i = 0; i < (1e6) + 10; i++)
      arr[i] = false;
    ll root = sqrt(u);
    //generating primes upto root (optional)
    for (int i = 2; i <= root; i++) {
      for (ll j = l + (l % i == 0 ? 0 : (i - (l % i))); j <= u; j += i) {
        if ( j <= i )
          continue ;
        arr[j - l] = true;
      }
    }
    for (int i = l; i <= u; i++) {
      if (!arr[i-l])
        printf("%d\n", i );
    }
  }

  return 0;
}
