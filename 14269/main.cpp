#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
struct Enemy {
  int a, b, c;
};

vector<Enemy> enemies;
vector<int> A_vector;
vector<pair<int, int>> BC_vector;

void solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    printf("0");
    return;
  }

  enemies.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &enemies[i].a, &enemies[i].b, &enemies[i].c);
    A_vector.push_back(enemies[i].a);
  }

  sort(A_vector.begin(), A_vector.end());
  A_vector.erase(unique(A_vector.begin(), A_vector.end()), A_vector.end());

  int a_cnt = A_vector.size();
  int bc_cnt = 0;

  for (int i = 0; i < n; i++) {
    int current_a = enemies[i].a;
    int b = enemies[i].b;
    int c = enemies[i].c;

    auto it = lower_bound(A_vector.begin(), A_vector.end(), b);

    bool covered = false;

    if (it != A_vector.end() && *it <= c) {
      if (*it != current_a) {
        covered = true;
      } else {
        auto next_it = it + 1;
        if (next_it != A_vector.end() && *next_it <= c) {
          covered = true;
        }
      }
    }

    // 없는 case
    if (!covered) {
      BC_vector.push_back(make_pair(b, c));
    }
  }

  sort(BC_vector.begin(), BC_vector.end(),
       [](pair<int, int> x, pair<int, int> y) { return x.second < y.second; });

  int curr = -1;
  for (auto iter = BC_vector.begin(); iter < BC_vector.end(); iter++) {
    int from = iter->first;
    int to = iter->second;
    if (curr < from) {
      bc_cnt++;
      curr = to;
    }
  }

  printf("%d", a_cnt + bc_cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();
  return 0;
}