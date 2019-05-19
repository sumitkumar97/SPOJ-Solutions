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

int dp[100010];
vector<vector<int>> grid;

int m, n;

vector<int> max_of_row;

int rec(int iter) { // iterating and selecting the rows
  if (iter >= m) {
    return 0;
  }
  int &ans = dp[iter];
  if (ans != -1)
    return ans;
  ans = rec(iter + 1);
  ans = max(ans, max_of_row[iter] + rec(iter + 2));
  return ans;
}

int with[100010];
int without[100010];
int main() {
  scanf("%d%d", &m, &n);
  int x;
  while (m > 0) {
    grid.clear();
    for (int i = 0; i < m; i++) {
      vector<int> empty;
      grid.pb(empty);
      for (int j = 0; j < n; j++) {
        scanf("%d", &x);
        grid[i].pb(x);
      }
      dp[i] = -1;
    }
    max_of_row.clear();
    for (int i = 0; i < m; i++) {
      without[0] = 0;
      with[0] = grid[i][0];
      for (int j = 1; j < n; j++) {
        without[j] = max(with[j - 1], without[j - 1]);
        with[j] = without[j - 1] + grid[i][j];
      }
      max_of_row.pb(max(with[n - 1], without[n - 1]));
    }
    printf("%d\n", rec(0));
    scanf("%d%d", &m, &n);
  }
  return 0;
}
