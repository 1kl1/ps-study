#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  return a * b / gcd(a, b);
}

void solve()
{
  int a, b;
  scanf("%d %d", &a, &b);
  int ab_gcd = gcd(a, b);
  int ab_lcm = lcm(a, b);
  int count = 0;
  for (int c = ab_gcd; c <= ab_lcm; c += ab_gcd)
  {
    if (ab_gcd == gcd(a, c) && ab_lcm == lcm(b, c))
      count++;
  }
  printf("%d", count);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
