#include <algorithm>
#include <iostream>

class Stack {
  struct Node {
    int val;
    int min;
    int max;
    Node* prev = nullptr;
    Node(int new_val, Node* par) {
      val = new_val;
      min = val;
      max = val;
      prev = par;
      if (prev != nullptr) {
        min = std::min(min, prev->min);
        max = std::max(max, prev->max);
      }
    }
  };

 public:
  Stack() : last_(nullptr) {}

  ~Stack() {
    while (last_ != nullptr) {
      PopLast();
    }
  }

  void Push(int val) { PushLast(val); }

  int Pop() {
    if (sz == 0) {
      return 0;
    }
    return PopLast();
  }

  int GetMin() {
    if (last_ == nullptr) {
      return kINF;
    }
    return last_->min;
  }

  int GetMax() {
    if (last_ == nullptr) {
      return -kINF;
    }
    return last_->max;
  }

  int sz = 0;
  int front = 0;
  int back = 0;

 private:
  void PushLast(int val) {
    Node* cur = new Node(val, last_);
    last_ = cur;
    if (sz == 0) {
      front = val;
    }
    back = val;
    ++sz;
  }

  int PopLast() {
    Node* cur = last_;
    int res = last_->val;
    last_ = last_->prev;
    delete cur;
    --sz;
    if (sz > 0) {
      back = last_->val;
    }
    return res;
  }

  Node* last_;
  const int kINF = 1e9 + 7;
};

class Queue {
 public:
  void Clear() {
    while (sz > 0) {
      Pop();
    }
    std::cout << "ok\n";
  }

  void Enqueue(int val) {
    Push(val);
    std::cout << "ok\n";
  }

  void Dequeue() {
    if (sz == 0) {
      std::cout << "error\n";
      return;
    }
    std::cout << Pop() << '\n';
  }

  int Size() { return sz; }

  void GetMin() {
    if (sz == 0) {
      std::cout << "error\n";
      return;
    }
    int res = std::min(left_.GetMin(), right_.GetMin());
    std::cout << res << '\n';
  }

  void Front() {
    if (sz == 0) {
      std::cout << "error\n";
      return;
    }
    if (right_.sz > 0) {
      std::cout << right_.back << '\n';
      return;
    }
    std::cout << left_.front << '\n';
  }

  int sz = 0;

 private:
  void Push(int val) {
    left_.Push(val);
    ++sz;
  }

  int Pop() {
    --sz;
    if (right_.sz > 0) {
      return right_.Pop();
    }
    while (left_.sz > 0) {
      right_.Push(left_.Pop());
    }
    return right_.Pop();
  }

  Stack left_;
  Stack right_;
};

int main() {
  int questions;
  std::cin >> questions;
  Queue tmp;
  for (int i = 0; i < questions; i++) {
    std::string ask;
    std::cin >> ask;

    if (ask == "enqueue") {
      int number;
      std::cin >> number;
      tmp.Enqueue(number);
    }
    if (ask == "dequeue") {
      tmp.Dequeue();
    }
    if (ask == "front") {
      tmp.Front();
    }
    if (ask == "size") {
      std::cout << tmp.Size() << '\n';
    }
    if (ask == "clear") {
      tmp.Clear();
    }
    if (ask == "min") {
      tmp.GetMin();
    }
  }
  return 0;
}
