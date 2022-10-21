#include <iostream>

int CalcAns(int sz) {
  int answer = 0, num;
  std::cin >> num;
  for (int i = 1; i < sz; i++) {
    int next_num;
    std::cin >> next_num;
    if (i != 0 && num > next_num) {
      answer = i;
    }
    num = next_num;
  }
  return answer;
}

int main() {
  int sz;
  std::cin >> sz;
  std::cout << CalcAns(sz);
  return 0;
}
