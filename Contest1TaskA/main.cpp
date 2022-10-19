#include <iostream>

using namespace std;
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
  cin >> num;

  for (int i = 0; i < num; i++) {
    cin >> arr[i];
  }

  int questions;
  cin >> questions;

  for (int i = 0; i < questions; i++) {
    int left, right, target;
    cin >> left >> right >> target;
    if (BinarySearch(&arr[left], &arr[right - 1], target)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
