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

int seg[4000010];

int lquery, rquery;
int query(int vertex, int lseg, int rseg) {
  if (rseg < lquery || rquery < lseg)
    return 0;
  if (lseg >= lquery && rseg <= rquery)
    return seg[vertex];
  int lchild = vertex << 1, mid = (lseg + rseg) >> 1;
  return query(lchild, lseg, mid) + query(lchild | 1, mid + 1, rseg);
}

int P, F;
void update(int vertex, int lseg, int rseg) {
  if (lseg > P || rseg < P)
    return;
  if (lseg == rseg && rseg == P) {
    seg[vertex] += F;
    return;
  }
  int lchild = vertex << 1, mid = (lseg + rseg) >> 1;
  update(lchild, lseg, mid);
  update(lchild | 1, mid + 1, rseg);
  seg[vertex] = seg[lchild] + seg[lchild|1];
}

int main() {
  int n, q, x, y;
  char s[20];
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%s%d%d", s, &x, &y);
    if (s[0] == 'f') {
      lquery = x;
      rquery = y;
      printf("%d\n", query(1, 1, n));
    } else {
      P = x;
      F = y;
      update(1, 1, n);
    }
  }
  return 0;
}
