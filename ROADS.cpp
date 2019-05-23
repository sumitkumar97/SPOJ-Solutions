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

vector<pair<int, ii>> adjlist[110]; // node, weight, cost

int n;
int dp[110][10010];

int rec(int iter, int remain) {
  if (remain < 0)
    return 1e7;
  if (iter == n) {
    return 0;
  }
  int &ans = dp[iter][remain];
  if (ans != -1)
    return ans;
  ans = 1e7;
  for (int i = 0; i < adjlist[iter].size(); i++) {
    ans = min(ans, adjlist[iter][i].second.first +
                       rec(adjlist[iter][i].first,
                           remain - adjlist[iter][i].second.second));
  }
  return ans;
}

int main() {
  int test;
  int k, r;
  scanf("%d", &test);
  while (test--) {
    scanf("%d%d%d", &k, &n, &r);
    for (int i = 1; i <= n; i++) {
      adjlist[i].clear();
      for (int j = 0; j < 10010; j++)
        dp[i][j] = -1;
    }
    int s, d, l, t;
    for (int i = 0; i < r; i++) {
      scanf("%d%d%d%d", &s, &d, &l, &t);
      adjlist[s].pb(mp(d, mp(l, t)));
    }
    int ans = rec(1, k);
    if (ans < (int)1e7)
      printf("%d\n", ans);
    else
      printf("-1\n");
  }
  return 0;
}
