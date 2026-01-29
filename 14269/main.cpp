#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

bool A_array[1000001];
int BC_array_tmp[1000001][2];
int BC_array[1000001][2];
vector<int> A_vector;

int cmp(const void *a, const void *b)
{
  int *rowA = (int *)a;
  int *rowB = (int *)b;
  return rowA[1] - rowB[1];
}

void solve()
{
  int n;
  scanf("%d", &n);
  if (n == 0)
  {
    printf("0");
    return;
  }
  int a_cnt = 0;
  int b_num = 0;
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (!A_array[a])
    {
      A_array[a] = true;
      a_cnt++;
      A_vector.push_back(a);
    }
    BC_array_tmp[i][0] = b;
    BC_array_tmp[i][1] = c;
  }

  for (int i = 0; i < n; i++)
  {
    bool flag = false;
    for (vector<int>::iterator iter = A_vector.begin(); iter < A_vector.end(); iter++)
    {
      int a = *iter;
      if (BC_array_tmp[i][0] <= a && a <= BC_array_tmp[i][1])
      {
        flag = true;
        continue;
      }
    }
    if (!flag)
    {
      BC_array[b_num][0] = BC_array_tmp[i][0];
      BC_array[b_num][1] = BC_array_tmp[i][1];
      b_num++;
    }
  }

  int bc_cnt = 0;
  if (b_num > 0)
  {
    qsort(BC_array, b_num, sizeof(int) * 2, cmp);
    int curr = BC_array[0][1];
    bc_cnt++;
    for (int i = 1; i < b_num; i++)
    {
      int from = BC_array[i][0];
      int to = BC_array[i][1];
      if (curr < from)
      {
        bc_cnt++;
        curr = to;
      }
    }
  }

  printf("%d", a_cnt + bc_cnt);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_n(A_array, 1000001, false);
  solve();
  return 0;
}
