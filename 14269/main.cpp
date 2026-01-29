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
pair<int, int> BC_array[1000001];
vector<int> A_vector;

struct Node
{
  int data;
  Node *left;
  Node *right;
};

Node *createNode(int data)
{
  Node *newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
}

bool insertNode(Node *root, int data)
{
  if (data < root->data)
  {
    if (root->left == NULL)
    {
      root->left = createNode(data);
      return true;
    }
    insertNode(root->left, data);
  }
}

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
  for (int i = 0; i < n; i++)
  {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
  }

  // qsort(BC_array, b_num, sizeof(int) * 2, cmp);
  // int curr = BC_array[0][1];

  // for (int i = 1; i < b_num; i++)
  // {
  //   int from = BC_array[i][0];
  //   int to = BC_array[i][1];
  //   if (curr < from)
  //   {
  //     bc_cnt++;
  //     curr = to;
  //   }
  // }

  printf("%d", a_cnt);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fill_n(A_array, 1000001, false);
  solve();
  return 0;
}
