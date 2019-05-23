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

int x[210], y[210];

int gcd(int x, int y) {
  if (y == 0)
    return x;
  return gcd(y, x % y);
}

int main() {
  int n;
  scanf("%d", &n);
  map<ii, int> mymap;
  while (n) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &x[i], &y[i]);
    }
    int ans = 0;
    mymap.clear();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int dy = (y[j] - y[i]);
        int dx = (x[j] - x[i]);
        int g = gcd(dy, dx);
        dy /= g;
        dx /= g;
        if (mymap.find(mp(dy, dx)) == mymap.end()) {
          ans ++ ;
          mymap[mp(dy, dx)];
        }
      }
    }
    printf("%d\n", ans);
    scanf("%d", &n);
  }
  return 0;
}
