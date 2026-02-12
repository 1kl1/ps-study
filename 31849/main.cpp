#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N, M, R, C;
int cost_map[1000][1000];
bool is_checked[1000][1000];
unordered_map<int, int> rooms;
vector<pair<int, int>> stores;

int covert(int x, int y) { return x * 10000 + y; }
pair<int, int> revert(int n) { return make_pair(n / 10000, n % 10000); }

void solve() {
  int covered_room_cnt = 0;
  queue<pair<int, int>> q;
  for (auto i = stores.begin(); i < stores.end(); i++) {
    q.push(*i);
    is_checked[(*i).first][(*i).second] = true;
    cost_map[(*i).first][(*i).second] = 0;
  }
  while (R > covered_room_cnt && !q.empty()) {
    auto front = q.front();
    q.pop();
    int x = front.first;
    int y = front.second;

    if (x - 1 >= 0 && !is_checked[x - 1][y]) {
      is_checked[x - 1][y] = true;
      cost_map[x - 1][y] = cost_map[x][y] + 1;
      q.push(make_pair(x - 1, y));
      if (rooms.find(covert(x - 1, y)) != rooms.end()) covered_room_cnt++;
    }
    if (x + 1 < N && !is_checked[x + 1][y]) {
      is_checked[x + 1][y] = true;
      cost_map[x + 1][y] = cost_map[x][y] + 1;
      q.push(make_pair(x + 1, y));
      if (rooms.find(covert(x + 1, y)) != rooms.end()) covered_room_cnt++;
    }
    if (y - 1 >= 0 && !is_checked[x][y - 1]) {
      is_checked[x][y - 1] = true;
      cost_map[x][y - 1] = cost_map[x][y] + 1;
      q.push(make_pair(x, y - 1));
      if (rooms.find(covert(x, y - 1)) != rooms.end()) covered_room_cnt++;
    }
    if (y + 1 < M && !is_checked[x][y + 1]) {
      is_checked[x][y + 1] = true;
      cost_map[x][y + 1] = cost_map[x][y] + 1;
      q.push(make_pair(x, y + 1));
      if (rooms.find(covert(x, y + 1)) != rooms.end()) covered_room_cnt++;
    }
  }

  // for (int x = 0; x < N; x++) {
  //   for (int y = 0; y < M; y++) {
  //     printf("%d ", cost_map[x][y]);
  //   }
  //   printf("\n");
  // }
  int min = 2000 * 100;
  for (auto room = rooms.begin(); room != rooms.end(); room++) {
    auto coordinate = revert(room->first);
    int score = cost_map[coordinate.first][coordinate.second] * room->second;
    // printf("%d %d -> %d * %d\n", coordinate.first, coordinate.second,
    //        room->second, cost_map[coordinate.first][coordinate.second]);
    if (score < min) min = score;
  }
  printf("%d", min);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d %d %d %d", &N, &M, &R, &C);
  for (int i = 0; i < R; i++) {
    int x, y, cost;
    scanf("%d %d %d", &x, &y, &cost);
    rooms.insert({covert(x - 1, y - 1), cost});
  }
  for (int i = 0; i < C; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    stores.push_back(make_pair(x - 1, y - 1));
  }

  solve();
  return 0;
}
