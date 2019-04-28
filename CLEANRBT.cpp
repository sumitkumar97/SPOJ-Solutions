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

int distNodes[30][30];
ii node[30];
int distPoints[30][30];
bool visited[30][30];

int offy[] = {0, 0, 1, -1};
int offx[] = {1, -1, 0, 0};
int coun;
int dp[30][8000][30];

int rec(int iter, int vis, int last) {
  if (iter == coun - 1) {
    return 0;
  }
  int &moves = dp[iter][vis][last];
  if (moves != -1)
    return moves;
  moves = 1e5;
  for (int i = 0; i < coun; i++) {
    if ((vis & (1 << i)) == 0) {
      moves = min(moves, distNodes[last][i] + rec(iter + 1, vis | (1 << i), i));
    }
  }
  return moves;
}

int main() {
  int w, h;
  char m[30][30];
  scanf("%d%d", &w, &h);
  int sourceNode;
  while (!(w == 0 && h == 0)) {
    coun = 0;
    for (int i = 0; i < h; i++) {
      scanf("%s", m[i]);
      for (int j = 0; j < w; j++) {
        if (m[i][j] == 'o' || m[i][j] == '*') {
          node[coun++] = mp(i, j);
        }
        if (m[i][j] == 'o')
          sourceNode = coun - 1;
      }
    }
    for (int i = 0; i <= coun; i++) {
      for (int j = 0; j < 8000; j++) {
        for (int k = 0; k <= coun; k++) {
          dp[i][j][k] = -1;
        }
      }
    }
    for (int i = 0; i < coun; i++) {
      int y = node[i].first;
      int x = node[i].second;
      for (int j = 0; j < h; j++) {
        for (int k = 0; k < w; k++) {
          distPoints[j][k] = 1e9;
          visited[j][k] = false;
        }
      }
      distPoints[y][x] = 0;
      visited[y][x] = true;
      queue<ii> q;
      q.push(mp(y, x));
      while (!q.empty()) {
        ii f = q.front();
        q.pop();
        for (int j = 0; j < 4; j++) {
          int newy = f.first + offy[j];
          int newx = f.second + offx[j];
          if (newy >= 0 && newy < h && newx >= 0 && newx < w &&
              !visited[newy][newx] && m[newy][newx] != 'x') {
            distPoints[newy][newx] = distPoints[f.first][f.second] + 1;
            q.push(mp(newy, newx));
            visited[newy][newx] = true;
          }
        }
      }
      for (int j = 0; j < coun; j++) {
        distNodes[i][j] = distPoints[node[j].first][node[j].second];
      }
    }
    int ans = rec(0, 1<<sourceNode, sourceNode);
    if (ans < 1e5)
      printf("%d\n", ans);
    else
      printf("-1\n");
    scanf("%d%d", &w, &h);
  }
  return 0;
}
