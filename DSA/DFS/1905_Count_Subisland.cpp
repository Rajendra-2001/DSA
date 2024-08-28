#include <iostream>
#include <vector>

using namespace std;
bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
{
  // Check for out-of-bound indices
  if (i < 0 || i >= grid2.size() || j < 0 || j >= grid2[0].size())
    return true;

  // If the current cell is not part of an island in grid2, return true
  if (grid2[i][j] != 1)
    return true;

  // Mark the current cell as visited in grid2
  grid2[i][j] = -1;

  // Result is true if the current cell is also part of an island in grid1
  bool result = (grid1[i][j] == 1);

  // Perform DFS in all four directions
  result &= dfs(grid1, grid2, i + 1, j);
  result &= dfs(grid1, grid2, i - 1, j);
  result &= dfs(grid1, grid2, i, j + 1);
  result &= dfs(grid1, grid2, i, j - 1);

  return result;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
  int m = grid2.size();    // Number of rows
  int n = grid2[0].size(); // Number of columns
  int ans = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      // If the cell in grid2 is part of an island and dfs returns true, increment ans
      if (grid2[i][j] == 1 && dfs(grid1, grid2, i, j))
      {
        ans++;
      }
    }
  }
  return ans;
}
int main()
{
  // Example grids
  vector<vector<int>> grid1 = {
      {1, 1, 1, 0, 0},
      {0, 1, 0, 0, 1},
      {1, 1, 0, 1, 1},
      {0, 1, 0, 1, 0},
      {1, 1, 0, 0, 1}};

  vector<vector<int>> grid2 = {
      {1, 1, 0, 0, 0},
      {0, 1, 0, 1, 1},
      {1, 1, 0, 1, 0},
      {0, 0, 0, 1, 0},
      {1, 1, 0, 0, 0}};

  // Call countSubIslands function
  int result = countSubIslands(grid1, grid2);

  // Output the result
  cout << "Number of sub-islands: " << result << endl;

  return 0;
}