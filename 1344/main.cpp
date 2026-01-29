#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const int primes[7] = {2, 3, 5, 7, 11, 13, 17};
unordered_map<int, double> facts;

double factorial(int n)
{
  unordered_map<int, double>::iterator cached = facts.find(n);
  if (cached != facts.end())
  {
    return cached->second;
  }
  double result = 1;
  for (int i = 1; i <= n; i++)
    result *= i;
  facts.insert({n, result});
  return result;
}

double cal_probability(int n, int prob)
{
  double p = prob / 100.0;
  double result = 1;
  result *= factorial(18) / (factorial(n) * factorial(18 - n));
  for (int i = 0; i < n; i++)
  {
    result *= p;
  }
  for (int i = 0; i < 18 - n; i++)
  {
    result *= (1.0 - p);
  }

  return result;
}

void solve()
{
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  double a_acc, b_acc = 0.0;
  for (int i = 0; i < 7; i++)
  {
    a_acc += cal_probability(primes[i], a);
    b_acc += cal_probability(primes[i], b);
  }

  double result = 1.0 - (1.0 - a_acc) * (1.0 - b_acc);
  printf("%lf", result);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
