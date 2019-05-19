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

char alice[100], bob[100];
int lena, lenb;

vector<string> dp[100][100];
bool done[100][100];
map<string, int> mymap;
map<string, int>::iterator it;

int coun;
vector<string> rec(int itera, int iterb) {
  if (itera >= lena || iterb >= lenb) {
    vector<string> x;
    x.pb("");
    return x;
  }
  vector<string> &ans = dp[itera][iterb];
  if (done[itera][iterb]) {
    return ans;
  }
  vector<string> ans1, ans2, ans3;
  ans1 = rec(itera + 1, iterb);
  ans2 = rec(itera, iterb + 1);
  if (alice[itera] == bob[iterb]) {
    ans3 = rec(itera + 1, iterb + 1);
    for (int i = 0; i < ans3.size(); i++) {
      ans3[i] = alice[itera] + ans3[i];
    }
  }
  int len1, len2, len3;
  len1 = len2 = len3 = 0;
  if (ans1.size() > 0) {
    len1 = ans1[0].length();
  }
  if (ans2.size() > 0) {
    len2 = ans2[0].length();
  }
  if (ans3.size() > 0) {
    len3 = ans3[0].length();
  }
  int maxi = max(len1, max(len2, len3));
  mymap.clear();
  for (int i = 0; i < ans1.size(); i++) {
    if (ans1[i].length() == maxi)
      mymap[ans1[i]];
  }
  for (int i = 0; i < ans2.size(); i++) {
    if (ans2[i].length() == maxi)
      mymap[ans2[i]];
  }
  for (int i = 0; i < ans3.size(); i++) {
    if (ans3[i].length() == maxi)
      mymap[ans3[i]];
  }
  for (it = mymap.begin(); it != mymap.end(); it++)
    ans.pb(it->first);
  done[itera][iterb] = true;
  return ans;
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%s%s", alice, bob);
    lena = strlen(alice);
    lenb = strlen(bob);
    for (int i = 0; i < lena; i++) {
      for (int j = 0; j < lenb; j++) {
        done[i][j] = false;
        dp[i][j].clear();
      }
    }
    coun = 0;
    vector<string> ans = rec(0, 0);
    for (int i = 0; i < ans.size(); i++)
      printf("%s\n", ans[i].data());
    printf("\n");
  }
  return 0;
}
