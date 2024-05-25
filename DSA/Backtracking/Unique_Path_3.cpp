class Solution
{
public:
  int obsCount, ans, m, n;
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void backtrack(vector<vector<int>> &grid, int count, int i, int j)
  {
    // Boundary check and obstacle check
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1)
      return;

    // Check if the current cell is the endpoint and if all non-obstacle cells are visited
    if (grid[i][j] == 2)
    {
      if (count == obsCount)
      {
        ans++;
      }
      return;
    }

    // Mark the cell as visited
    grid[i][j] = -1;

    // Try all four directions
    for (auto &dir : directions)
    {
      int new_i = i + dir[0];
      int new_j = j + dir[1];
      backtrack(grid, count + 1, new_i, new_j);
    }

    // Unmark the cell to allow for other paths
    grid[i][j] = 0;
  }

  int uniquePathsIII(vector<vector<int>> &grid)
  {
    ans = 0;
    m = grid.size();
    n = grid[0].size();
    obsCount = 0;
    int start_i, start_j;

    // Count non-obstacle cells and find the starting point
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] != -1)
          obsCount++;
        if (grid[i][j] == 1)
        {
          start_i = i;
          start_j = j;
        }
      }
    }

    // Perform backtracking from the starting point
    backtrack(grid, 1, start_i, start_j);

    return ans;
  }
};
