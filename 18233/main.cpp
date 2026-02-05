#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N, P, E;

struct Member {
  int x, y;
};

vector<Member> members;
bool selected[25];

void solve(int idx, int count, int current_min_sum, int current_max_sum) {
  if (current_min_sum > E) return;

  if (count == P) {
    if (current_min_sum <= E && E <= current_max_sum) {
      int remain = E - current_min_sum;
      for (int i = 0; i < N; i++) {
        if (selected[i]) {
          int give = members[i].x;
          int capacity = members[i].y - members[i].x;
          int add = (remain < capacity) ? remain : capacity;

          give += add;
          remain -= add;

          printf("%d ", give);
        } else {
          printf("0 ");
        }
      }
      exit(0);
    }
    return;
  }

  if (idx == N) return;

  selected[idx] = true;
  solve(idx + 1, count + 1, current_min_sum + members[idx].x,
        current_max_sum + members[idx].y);
  selected[idx] = false;

  if (count + (N - 1 - idx) >= P) {
    solve(idx + 1, count, current_min_sum, current_max_sum);
  }
}

int main() {
  scanf("%d %d %d", &N, &P, &E);

  for (int i = 0; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    members.push_back({x, y});
  }

  solve(0, 0, 0, 0);

  printf("-1");

  return 0;
}