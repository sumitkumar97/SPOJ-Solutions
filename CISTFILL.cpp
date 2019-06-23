#include <cstdio>
#include <iostream>
using namespace std;

int n;
double b[(int)5e4 + 10], h[(int)5e4 + 10], w[(int)5e4 + 10], d[(int)5e4 + 10],
    v;

bool com_fill(double x) {
  if (x < 1e-7)
    return true;
  double sum = 0;
  for (int i = 0; i < n; i++) {
    if (x > b[i])
      sum += (min(b[i] + h[i] - 1e-7, x) - b[i] + 1e-7) * w[i] * d[i];
  }
  return v - sum > 1e-7;
}

double binary(double low, double high) {
  if (low - high > 1e-7)
    return low;
  double mid = (low + high) / 2;
  if (com_fill(mid)) {
    double x = binary(mid + (1e-7), high);
    if (com_fill(x))
      return x;
    return mid;
  }
  return binary(low, mid - (1e-7));
}

int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d", &n);
    double maxi = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &b[i], &h[i], &w[i], &d[i]);
      if (b[i] + h[i] > maxi)
        maxi = b[i] + h[i];
    }
    scanf("%lf", &v);
    double res = binary(0, 1e7);
    if (res > maxi)
      printf("OVERFLOW\n");
    else
      printf("%.2lf\n", res);
  }
  return 0;
}
