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

ll mod = 1e9 + 7;

int main() {
  int test;
  ll n, arr[70];
  scanf("%d", &test);
  while (test--) {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
      scanf("%lld", &arr[i]);
    sort(arr, arr + n);
    ll ans = arr[0] % mod;
    for (int i = 1; i < n; i++) {
      ans = (ans * (arr[i] - i)) % mod;
    }
    printf("%lld\n", ans);
  }
  printf("KILL BATMAN");
  return 0;
}
