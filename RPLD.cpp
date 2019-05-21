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

int main() {
  int test;
  scanf("%d", &test);
  int n, r;
  set<ii> myset;
  for (int t = 1; t <= test; t++) {
    scanf("%d%d", &n, &r);
    int a, b;
    myset.clear();
    bool poss = true;
    for (int i = 0; i < r; i++) {
      scanf("%d%d", &a, &b);
      if (!poss)
        continue;
      if (myset.find(mp(a, b)) == myset.end())
        myset.insert(mp(a, b));
      else
        poss = false;
    }
    printf("Scenario #%d: %s\n", t, (poss ? "possible" : "impossible"));
  }
  return 0;
}
