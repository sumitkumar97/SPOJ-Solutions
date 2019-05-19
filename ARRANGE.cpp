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

int arr[100010];

int main() {
  int test, n;
  scanf("%d", &test);
  while (test--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    sort(arr, arr + n);
    int j = 0;
    while (arr[j] == 1) {
      printf("1 ");
      j++;
    }
    if (j == n - 2 && arr[j] == 2 && arr[j + 1] == 3)
      printf("2 3");
    else {
      for (int k = n - 1; k >= j; k--)
        printf("%d ", arr[k]);
    }
    printf("\n");
  }
  return 0;
}
