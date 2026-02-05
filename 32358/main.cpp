#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
long long calc(multiset<int>& trees, int& current_pos) {
  long long acc = 0;
  while (!trees.empty()) {
    auto it = trees.lower_bound(current_pos);

    int target;
    if (it == trees.end()) {
      target = *trees.rbegin();
    } else if (it == trees.begin()) {
      target = *it;
    } else {
      int right = *it;
      int left = *prev(it);

      int dist_right = abs(right - current_pos);
      int dist_left = abs(left - current_pos);

      if (dist_left <= dist_right) {
        target = left;
      } else {
        target = right;
      }
    }

    acc += abs(target - current_pos);
    current_pos = target;
    trees.erase(trees.find(target));
  }
  return acc;
}

void solve() {
  multiset<int> trees;
  int n;
  scanf("%d", &n);
  long long result = 0;
  int current_pos = 0;

  for (int i = 0; i < n; i++) {
    int command;
    scanf("%d", &command);
    if (command == 1) {
      int x;
      scanf("%d", &x);
      trees.insert(x);
    } else {
      result += calc(trees, current_pos);
    }
  }
  printf("%lld\n", result);
}

int main() {
  solve();
  return 0;
}