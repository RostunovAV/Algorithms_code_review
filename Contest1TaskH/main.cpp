#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
const int kSize = 3e5 + 3, kINF = 1e9 + 7;
double pref[kSize];

int main() {
  int sz;
  cin >> sz;

  for (int i = 0; i < sz; i++) {
    double num;
    cin >> num;
    pref[i] += log(num);
    if (i > 0) {
      pref[i] += pref[i - 1];
    }
  }

  int questions;
  cin >> questions;
  cout << fixed << setprecision(40);

  for (int i = 0; i < questions; i++) {
    int left, right;
    cin >> left >> right;
    double sum_ln = pref[right];
    if (left > 0) {
      sum_ln -= pref[left - 1];
    }
    int len = right - left + 1;
    double res = exp(sum_ln / len);
    cout << res << '\n';
  }

  return 0;
}
