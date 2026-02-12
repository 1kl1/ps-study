#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N, M, K;
vector<pair<vector<int>, int>> selected_rings;

void solve() {
  for

    int smallest = 100000;

  printf("%d", smallest);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d %d %d", &N, &M, &K);
  int tmp = 0;
  vector<int> splits;
  for (int i = 0; i < M; i++) {
    int x;
    scanf("%d", &x);
    splits.push_back(x);
    tmp = x;
  }
  splits.push_back(N - tmp);
  selected_rings.push_back(make_pair(splits, N));
  solve();
  return 0;
}
