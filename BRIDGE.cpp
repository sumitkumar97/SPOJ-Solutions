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

int n;

ii arr[1010];
int dp[1010][1010];

bool custom_sort(ii a, ii b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int rec(int iter, int maxi) {
  if (iter == n)
    return 0;
  int &ans = dp[iter][maxi];
  if (dp[iter][maxi] != -1)
    return dp[iter][maxi];
  ans = rec(iter + 1, maxi);
  if (maxi == n || arr[iter].first >= arr[maxi].first)
    ans = max(ans, 1 + rec(iter + 1, iter));
  return ans;
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i].first);
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i].second);
    sort(arr, arr + n, custom_sort);
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j] = -1;
    printf("%d\n", rec(0, n));
  }
  return 0;
}
