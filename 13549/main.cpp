#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool checked[100001];
int cost[100001];

bool check(int a, int b)
{
  if (a == b)
    return true;
  if (a > b || a == 0)
    return false;
  return check(a * 2, b);
}

void search(int a, int b)
{
  queue<int> q;
  checked[a] = true;
  q.push(a);

  while (!q.empty())
  {
    int newA = q.front();
    // printf("%d\n", newA);
    q.pop();

    if (check(newA, b))
    {
      printf("%d", cost[newA]);
      return;
    }

    if (newA * 2 <= 100000)
    {
      if (!checked[newA * 2])
      {
        checked[newA * 2] = true;
        q.push(newA * 2);
        cost[newA * 2] = cost[newA];
      }
    }

    if (newA - 1 >= 0)
    {
      if (!checked[newA - 1])
      {
        checked[newA - 1] = true;
        q.push(newA - 1);
        cost[newA - 1] = cost[newA] + 1;
      }
    }
    if (newA + 1 <= 100000)
    {
      if (!checked[newA + 1])
      {
        checked[newA + 1] = true;
        q.push(newA + 1);
        cost[newA + 1] = cost[newA] + 1;
      }
    }
  }
}

void solve()
{
  int a, b;
  scanf("%d %d", &a, &b);
  if (a >= b)
  {
    printf("%d", a - b);
    return;
  }
  search(a, b);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_n(checked, 100001, false);
  fill_n(cost, 100001, 0);
  solve();
  return 0;
}
