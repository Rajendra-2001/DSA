#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define the solve and maxMoves functions
int solve(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp, int prev)
{
  if (j >= m || i < 0 || i >= n)
    return 0; // Out of bounds
  int x = grid[i][j];
  if (x <= prev)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j]; // Return cached result if computed

  int dig_up = solve(i - 1, j + 1, n, m, grid, dp, x);
  int right = solve(i, j + 1, n, m, grid, dp, x);
  int dig_down = solve(i + 1, j + 1, n, m, grid, dp, x);

  // Current cell + maximum moves from any of the three directions
  dp[i][j] = 1 + max({dig_up, right, dig_down});
  return dp[i][j];
}

int maxMoves(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  int max_moves = 0;

  // DP table initialized to -1 for memoization
  vector<vector<int>> dp(n, vector<int>(m, -1));

  // Start from all cells in the first column
  for (int i = 0; i < n; i++)
  {
    max_moves = max(max_moves, solve(i, 0, n, m, grid, dp, -1));
  }

  return max_moves - 1; // Subtract 1 to exclude the starting position
}

int main()
{
  // Example input
  vector<vector<int>> grid = {
      {2, 3, 4},
      {0, 4, 5},
      {3, 2, 1}};

  // Call maxMoves and print the result
  int result = maxMoves(grid);
  cout << "Maximum possible moves in the grid: " << result << endl;

  return 0;
}
