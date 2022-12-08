#include <cmath>
#include <iomanip>
#include <iostream>

void Read(double* arr, size_t& sz) {
  for (size_t i = 0; i < sz; i++) {
    double num;
    std::cin >> num;
    arr[i] = log(num);
    if (i > 0) {
      arr[i] += arr[i - 1];
    }
  }
}

void Calc(const double* arr) {
  size_t questions;
  std::cin >> questions;
  std::cout << std::fixed << std::setprecision(40);

  for (size_t i = 0; i < questions; i++) {
    int left, right;
    std::cin >> left >> right;
    double sum_ln = arr[right];
    if (left > 0) {
      sum_ln -= arr[left - 1];
    }
    int len = right - left + 1;
    double res = exp(sum_ln / len);
    std::cout << res << '\n';
  }
}

int main() {
  size_t sz;
  std::cin >> sz;
  double* arr = new double[sz];
  Read(arr, sz);
  Calc(arr);
  delete[] arr;
  return 0;
}
