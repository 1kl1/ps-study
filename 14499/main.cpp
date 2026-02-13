#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N, M, x, y, K;
int _map[20][20];
vector<int> instructions;
int moves[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

class Dice {
 public:
  int top() const { return faces[TOP]; }
  int bottom() const { return faces[BOTTOM]; }
  void update_bottom(int value) { faces[BOTTOM] = value; }

  void roll(int direction) {
    switch (direction) {
      case 1:
        cycle(TOP, EAST, BOTTOM, WEST);
        break;
      case 0:
        cycle(TOP, WEST, BOTTOM, EAST);
        break;
      case 2:
        cycle(TOP, SOUTH, BOTTOM, NORTH);
        break;
      case 3:
        cycle(TOP, NORTH, BOTTOM, SOUTH);
        break;
    }
  }

 private:
  static const int TOP = 0, BOTTOM = 1, NORTH = 2, SOUTH = 3, WEST = 4,
                   EAST = 5;
  std::array<int, 6> faces{0, 0, 0, 0, 0, 0};

  void cycle(int a, int b, int c, int d) {
    int tmp = faces[a];
    faces[a] = faces[b];
    faces[b] = faces[c];
    faces[c] = faces[d];
    faces[d] = tmp;
  }
};

void solve() {
  Dice dice;

  for (auto it = instructions.begin(); it < instructions.end(); it++) {
    int* move = moves[*it];

    if (x + move[0] < 0 || M <= x + move[0]) continue;
    if (y + move[1] < 0 || N <= y + move[1]) continue;
    dice.roll((*it));
    x += move[0];
    y += move[1];
    printf("%d\n", dice.top());
    if (_map[y][x] == 0) {
      _map[y][x] = dice.bottom();
    } else {
      dice.update_bottom(_map[y][x]);
      _map[y][x] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &_map[i][j]);
    }
  }
  for (int i = 0; i < K; i++) {
    int x;
    scanf("%d", &x);
    instructions.push_back(x - 1);
  }

  solve();

  return 0;
}
