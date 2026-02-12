#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// string current_substring = "";
// string max_substring = "";
// // int cnt = 0;

// bool is_possible(string substring, string B) {
//   auto target = substring.begin();
//   for (auto c = B.begin(); c < B.end(); c++) {
//     if (*target == *c) {
//       target += 1;
//       if (target == substring.end()) break;
//     }
//   }
//   return target == substring.end();
// }

// void search(int idx, string A, string B) {
//   // cnt++;
//   if (current_substring.length() > max_substring.length()) {
//     if (is_possible(current_substring, B)) {
//       max_substring = current_substring;
//     } else {
//       return;
//     }
//   }

//   if (idx > min(A.length(), B.length())) return;
//   current_substring.push_back(A[idx]);
//   search(idx + 1, A, B);
//   current_substring.pop_back();
//   search(idx + 1, A, B);
// }

// void solve() {
//   string A, B;
//   getline(cin, A);
//   getline(cin, B);
//   search(0, A, B);
// }

int dp[41][41];

void solve() {
  string A, B;
  getline(cin, A);
  getline(cin, B);

  for (int i = 1; i <= A.length(); i++) {
    for (int j = 1; j <= B.length(); j++) {
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string pw = "";
  int i = A.length();
  int j = B.length();

  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      pw.push_back(A[i - 1]);
      i--;
      j--;
    }
  }
  reverse(pw.begin(), pw.end());
  printf("%s", pw.c_str());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  // printf("%s", max_substring.c_str());
  // printf("%d", cnt);
  return 0;
}
