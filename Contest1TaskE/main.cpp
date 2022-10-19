#include <algorithm>
#include <iostream>

const int kSize = 2e5 + 3, kINF = 1e9 + 7;
int left_stack[kSize], right_stack[kSize];
int min_left[kSize], min_right[kSize];

void Push(int num, int& ind_right) {
  ind_right++;
  right_stack[ind_right] = num;
  if (ind_right > 0) {
    min_right[ind_right] = std::min(min_right[ind_right - 1], num);
  } else {
    min_right[ind_right] = num;
  }
  std::cout << "ok\n";
}

void Pop(int& ind_left, int& ind_right) {
  if (ind_left == -1 && ind_right == -1) {
    std::cout << "error\n";
    return;
  }

  if (ind_left == -1) {
    while (ind_right > -1) {
      ind_left++;
      int num = right_stack[ind_right];
      left_stack[ind_left] = num;
      if (ind_left > 0) {
        min_left[ind_left] = std::min(min_left[ind_left - 1], num);
      } else {
        min_left[ind_left] = num;
      }
      ind_right--;
    }
  }
  std::cout << left_stack[ind_left] << '\n';
  ind_left--;
}

void Front(int& ind_left, int& ind_right) {
  if (ind_right == -1 && ind_left == -1) {
    std::cout << "error\n";
    return;
  }
  if (ind_left != -1) {
    std::cout << left_stack[ind_left] << '\n';
    return;
  }
  std::cout << right_stack[0] << '\n';
}

void Size(int& ind_left, int& ind_right) {
  int res = ind_left + ind_right + 2;
  std::cout << res << '\n';
}

void Clear(int& ind_left, int& ind_right) {
  ind_left = -1;
  ind_right = -1;
  std::cout << "ok\n";
}

void Min(int& ind_left, int& ind_right) {
  if (ind_left == -1 && ind_right == -1) {
    std::cout << "error\n";
    return;
  }
  int res = kINF;
  if (ind_left != -1) {
    res = std::min(res, min_left[ind_left]);
  }
  if (ind_right != -1) {
    res = std::min(res, min_right[ind_right]);
  }

  std::cout << res << '\n';
}

int main() {
  int questions;
  std::cin >> questions;

  int ind_left = -1, ind_right = -1;
  for (int i = 0; i < questions; i++) {
    std::string ask;
    std::cin >> ask;

    if (ask == "enqueue") {
      int number;
      std::cin >> number;
      Push(number, ind_right);
    } else if (ask == "dequeue") {
      Pop(ind_left, ind_right);
    } else if (ask == "front") {
      Front(ind_left, ind_right);
    } else if (ask == "size") {
      Size(ind_left, ind_right);
    } else if (ask == "clear") {
      Clear(ind_left, ind_right);
    } else if (ask == "min") {
      Min(ind_left, ind_right);
    }
  }

  return 0;
}
