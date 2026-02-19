#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> meetings;

void solve() {
  sort(meetings.begin(), meetings.end(),
       [](const pair<int, int> a, const pair<int, int> b) {
         if (a.second == b.second) {
           return a.first < b.first;
         }
         return a.second < b.second;
       });

  int cnt = 0, end_time = -1;
  for (auto& meeting : meetings) {
    // printf("%d %d\n", meeting.first, meeting.second);
    if (end_time <= meeting.first) {
      cnt += 1;
      end_time = meeting.second;
    }
  }
  printf("%d", cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    meetings.push_back(make_pair(a, b));
  }

  solve();
  return 0;
}
