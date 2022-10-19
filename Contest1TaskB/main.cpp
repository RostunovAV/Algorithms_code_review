#include <iostream>

const int kKsize = 1e5 + 3;
int arr[kKsize];

int main() {
  int num, answer = 0;
  std::cin >> num;

  for (int i = 0; i < num; i++) {
    std::cin >> arr[i];
    if (i != 0 && arr[i - 1] > arr[i]) {
      answer = i;
    }
  }

  std::cout << answer;
  return 0;
}
