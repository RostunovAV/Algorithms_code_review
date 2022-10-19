#include <iostream>

const int kKsize = 1e5 + 3;
int arr[kKsize];

bool BinarySearch(int* begin, const int* end, int target) {
  while (begin + 1 < end) {
    int lengh = (end - begin + 1);
    int* middle = begin + lengh / 2;
    if (*middle < target) {
      begin = middle;
    } else {
      end = middle;
    }
  }
  return (*begin == target) || (*end == target);
}

int main() {
  int num;
  std::cin >> num;

  for (int i = 0; i < num; i++) {
    std::cin >> arr[i];
  }

  int questions;
  std::cin >> questions;

  for (int i = 0; i < questions; i++) {
    int left, right, target;
    std::cin >> left >> right >> target;
    if (BinarySearch(&arr[left], &arr[right - 1], target)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
  return 0;
}
