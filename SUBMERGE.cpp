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

vector<int> adjlist[10010];
bool visited[10010];
int dep[10010];
int ans;
int childcoun[10010];

int dfs(int u, int parent, int depth) {
  visited[u] = true;
  dep[u] = depth;
  int mini1 = 2e9, mini2 = 2e9;
  bool flag = false;
  for (int i = 0; i < adjlist[u].size(); i++) {
    if (visited[adjlist[u][i]]) {
      if (adjlist[u][i] != parent) { // back edge
        mini2 = min(mini2, dep[adjlist[u][i]]);
      }
    } else {
      int x = dfs(adjlist[u][i], u, depth + 1);
      if (x >= dep[u])
        flag = true;
      childcoun[u]++;
      mini1 = min(mini1, x);
    }
  }
  if (flag) {
    ans++;
  }
  return min(mini1, mini2);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int u, v;
  while (n != 0) {
    for (int i = 1; i <= n; i++) {
      adjlist[i].clear();
      visited[i] = false;
      childcoun[i] = 0;
    }
    ans = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      adjlist[u].pb(v);
      adjlist[v].pb(u);
    }
    dfs(1, -1, 0);
    if (childcoun[1] == 1)
      ans--;
    printf("%d\n", ans);
    scanf("%d%d", &n, &m);
  }
  return 0;
}
