#include <iostream>
#include <string>
#include <vector>

struct Heap {
  const int kINF = 1e9 + 7;
  int sz_min = 0;
  std::vector<std::pair<int, int>> arr_min;
  std::vector<int> id_min;

  void SwapMin(int i, int j) {
    std::swap(arr_min[i], arr_min[j]);
    std::swap(id_min[arr_min[i].second], id_min[arr_min[j].second]);
  }

  void SiffleUpMin(int ind) {
    int value = arr_min[ind].first;
    while (ind > 0) {
      int prev_ind = (ind - 1) / 2;
      int prev = arr_min[prev_ind].first;
      if (value < prev) {
        SwapMin(ind, prev_ind);
        ind = prev_ind;
      } else {
        break;
      }
    }
  }

  void InsertMin(int value, int i) {
    int ind = sz_min;
    ++sz_min;
    arr_min.push_back(std::make_pair(value, i));
    id_min.push_back(ind);

    SiffleUpMin(ind);
  }

  std::pair<int, int> GetMin() { return arr_min[0]; }

  void SiffleDownMin(int ind) {
    int value = arr_min[ind].first;
    while (ind * 2 + 1 < sz_min) {
      int left_ind = ind * 2 + 1;
      int right_ind = ind * 2 + 2;
      int left = arr_min[left_ind].first;
      int right = kINF;
      if (right_ind < sz_min) {
        right = arr_min[right_ind].first;
      }
      if (left_ind < sz_min && value > left && left <= right) {
        SwapMin(ind, left_ind);
        ind = left_ind;
      } else if (right_ind < sz_min && value > right && left > right) {
        SwapMin(ind, right_ind);
        ind = right_ind;
      } else {
        break;
      }
    }
  }

  void ExtractMin(int ind) {
    SwapMin(ind, sz_min - 1);
    --sz_min;
    arr_min.pop_back();
    if (sz_min < 2) {
      return;
    }
    SiffleDownMin(ind);
  }
};

void MergeK(std::vector<int>& tmp_sz, std::vector<std::vector<int>>& tmp,
  std::vector<int>& ans) {
  int sz = tmp.size();
  Heap k_heap;
  std::vector<int> ind_sz(sz);
  int cnt = sz;

  for (int i = 0; i < sz; i++) {
    k_heap.InsertMin(tmp[i][0], i);
  }

  while (cnt > 0) {
    std::pair<int, int> top = k_heap.GetMin();
    k_heap.ExtractMin(0);
    int ind = top.second;
    ans.push_back(top.first);
    ++ind_sz[ind];
    if (ind_sz[ind] == tmp_sz[ind]) {
      cnt--;
    } else {
      k_heap.InsertMin(tmp[ind][ind_sz[ind]], ind);
    }
  }
}

int main() {
  std::cin.tie(NULL);
  int sz;
  std::cin >> sz;

  std::vector<std::vector<int>> tmp(sz);
  std::vector<int> tmp_sz(sz);

  for (int i = 0; i < sz; i++) {
    std::cin >> tmp_sz[i];
    tmp[i].resize(tmp_sz[i]);
    for (int j = 0; j < tmp_sz[i]; j++) {
      std::cin >> tmp[i][j];
    }
  }

  std::vector<int> ans;
  MergeK(tmp_sz, tmp, ans);

  for (int x : ans) {
    std::cout << x << " ";
  }
}
