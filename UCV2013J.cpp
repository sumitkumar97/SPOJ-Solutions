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

int main() {
  int n;
  scanf("%d", &n);
  while (n > 0) {
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    int j = 1;
    ll one = 1;
    while (n - ((one << j) - 1) > 0) {
      j++;
    }
    j -= 2;
    int x = n - (one << j) + 1;
    int y = n - (one << (j + 1)) + 1;
    ll ans = 0;
    for (int i = 0; i < x - ((y + 1) >> 1); i++)
      ans += arr[n - 1 - i];
    printf("%lld\n", ans);
    scanf("%d", &n);
  }
  return 0;
}
