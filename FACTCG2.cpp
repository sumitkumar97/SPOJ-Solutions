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

int isprime[10000010];

int main() {
  int n;
  for (int i = 1; i <= 1e7; i++)
    isprime[i] = i;
  for (int i = 2; i <= 1e7; i++) {
    if (isprime[i] == i) {
      for (int j = i << 1; j <= 1e7; j += i) {
        isprime[j] = i;
      }
    }
  }
  vector<int> primes;
  while (scanf("%d", &n) != EOF) {
    primes.clear();
    while (isprime[n] != n) {
      primes.pb(isprime[n]);
      n /= isprime[n];
    }
    primes.pb(isprime[n]);
    sort(primes.begin(), primes.end());
    printf("1");
    for (int i = 0; i < (int)primes.sz; i++) {
      printf(" x ");
      printf("%d", primes[i]);
    }
    printf("\n");
  }
  return 0;
}
