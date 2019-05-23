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
  double p0, p1, t, p, x;
  scanf("%d", &test);
  for (int i = 1; i <= test; i++) {
    scanf("%lf%lf%lf%lf", &p0, &p1, &t, &p);
    x = pow((p1 / p0), ((double)1 / t));
    double ans = (double)log(p / p0) / log(x);
    printf("Scenario #%d: %.2lf\n", i, ans);
  }
  return 0;
}
