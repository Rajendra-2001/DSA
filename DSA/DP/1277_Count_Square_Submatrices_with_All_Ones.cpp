#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp, int n, int m)
{
  // Base case: Out of bounds or cell is zero
  if (i >= n || j >= m || mat[i][j] == 0)
    return 0;

  // If already computed, return stored value
  if (dp[i][j] != -1)
    return dp[i][j];

  // Recursive calls for right, below, and diagonal cells
  int right = solve(i, j + 1, mat, dp, n, m);
  int below = solve(i + 1, j, mat, dp, n, m);
  int diagonal = solve(i + 1, j + 1, mat, dp, n, m);

  // Minimum of neighboring cells plus 1 for current cell if it's 1
  dp[i][j] = 1 + min({right, below, diagonal});
  return dp[i][j];
}

int countSquares(vector<vector<int>> &mat)
{
  int n = mat.size();
  int m = mat[0].size();
  vector<vector<int>> dp(n, vector<int>(m, -1));
  int totalSquares = 0;

  // Loop through each cell in the matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // Count squares ending at each cell
      totalSquares += solve(i, j, mat, dp, n, m);
    }
  }
  return totalSquares;
}

int main()
{
  vector<vector<int>> mat = {
      {1, 0, 1},
      {1, 1, 0},
      {1, 1, 0}};
  cout << "Total square submatrices with all 1s: " << countSquares(mat) << endl;
  return 0;
}
