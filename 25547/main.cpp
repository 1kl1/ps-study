#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int lcm(int a, int b) { return a * b / gcd(a, b); }
void solve() {
  int A, B;
  scanf("%d %d", &A, &B);
  if (B % A != 0) {
    printf("0");
    return;
  }

  int y = B / A, cnt = 0;
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      cnt++;
      if (i * i < y) cnt++;
    }
  }

  printf("%d", cnt);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  solve();

  return 0;
}
