#include <time.h>
#include <iostream>
#include <vector>

void QuickSort(std::vector<int>& arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int i = left, j = right;
  int ind = i + rand() % (j - i + 1);
  int item = arr[ind];

  while (i <= j) {
    while (arr[i] < item) {
      i++;
    }
    while (arr[j] > item) {
      j--;
    }
    if (i <= j) {
      std::swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }

  QuickSort(arr, left, j);
  QuickSort(arr, j + 1, right);
}

int main() {
  srand(time(NULL));
  int sz;
  std::cin >> sz;
  std::vector<int> arr(sz);

  for (int i = 0; i < sz; i++) {
    std::cin >> arr[i];
  }

  QuickSort(arr, 0, sz - 1);

  for (int val : arr) {
    std::cout << val << " ";
  }
}
