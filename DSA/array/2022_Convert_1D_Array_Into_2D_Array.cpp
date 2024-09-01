#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
{
  if (original.size() != m * n)
  {
    return {};
  }

  vector<vector<int>> ans(m, vector<int>(n));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans[i][j] = original[i * n + j];
    }
  }

  return ans;
}

int main()
{
  vector<int> original = {1, 2, 3, 4, 5, 6};
  int m = 2, n = 3;

  vector<vector<int>> result = construct2DArray(original, m, n);

  for (const auto &row : result)
  {
    for (const auto &val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}