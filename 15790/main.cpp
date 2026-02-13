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
vector<int> X, Y;

bool check(int est) {
  if (K == 1) return est <= N;

  for (int i = 0; i < M; i++) {
    int idx = i;
    int cur = Y[idx];

    bool ok = true;
    for (int t = 1; t < K; t++) {
      int need = cur + est;
      auto it = lower_bound(Y.begin() + idx + 1, Y.begin() + i + M, need);
      if (it == Y.begin() + i + M) {  // 불가능
        ok = false;
        break;
      }
      idx = it - Y.begin();  // 가능
      cur = Y[idx];
    }

    if (!ok) continue;

    if (Y[i] + N - cur >= est) return true;  // 마지막 조각
  }

  return false;
}

void solve() {
  int result = -1;
  int low = 1, high = N;

  while (low <= high) {
    int est = (low + high) / 2;
    if (check(est)) {  // 만드는게 가능
      low = est + 1;
      result = est;
    } else {
      high = est - 1;
    }
  }
  printf("%d", result);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d %d %d", &N, &M, &K);

  for (int i = 0; i < M; i++) {
    int x;
    scanf("%d", &x);
    X.push_back(x);
  }

  int M = X.size();
  Y.resize(M * 2);
  for (int i = 0; i < M; i++) {
    Y[i] = X[i];
    Y[i + M] = X[i] + N;
  }  // 선형으로 펼치기

  solve();
  return 0;
}
