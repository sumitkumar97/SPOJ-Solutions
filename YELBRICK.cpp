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

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  ll n, a[1010], b[1010], c[1010];
  scanf("%lld", &n);
  while (n != 0) {
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    ll Gcd = gcd(a[0], b[0]);
    Gcd = gcd(Gcd, c[0]);
    for (int i = 1; i < n; i++) {
      Gcd = gcd(Gcd, a[i]);
      Gcd = gcd(Gcd, b[i]);
      Gcd = gcd(Gcd, c[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (a[i] / Gcd) * (b[i] / Gcd) * (c[i] / Gcd);
    }
    printf("%lld\n", ans);
    scanf("%lld", &n);
  }
  return 0;
}
