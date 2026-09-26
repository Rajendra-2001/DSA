#include <bits/stdc++.h>
using namespace std;

// 1. Recursion
int recursion(vector<int> &heights, int idx)
{
  if (idx == 0)
    return 0;

  int oneJump = recursion(heights, idx - 1) + abs(heights[idx] - heights[idx - 1]);

  int twoJump = INT_MAX;

  if (idx > 1)
  {
    twoJump = recursion(heights, idx - 2) + abs(heights[idx] - heights[idx - 2]);
  }

  return min(oneJump, twoJump);
}

// 2. Memoization
int memoization(vector<int> &heights, int idx, vector<int> &dp)
{
  if (idx == 0)
    return 0;

  if (dp[idx] != -1)
    return dp[idx];

  int oneJump = memoization(heights, idx - 1, dp) + abs(heights[idx] - heights[idx - 1]);

  int twoJump = INT_MAX;

  if (idx > 1)
  {
    twoJump = memoization(heights, idx - 2, dp) + abs(heights[idx] - heights[idx - 2]);
  }

  dp[idx] = min(oneJump, twoJump);

  return dp[idx];
}

// 3. Tabulation
int tabulation(vector<int> &heights)
{
  int n = heights.size();

  vector<int> dp(n, 0);

  dp[0] = 0;

  for (int i = 1; i < n; i++)
  {
    int oneJump = dp[i - 1] + abs(heights[i] - heights[i - 1]);

    int twoJump = INT_MAX;

    if (i > 1)
    {
      twoJump = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    }

    dp[i] = min(oneJump, twoJump);
  }

  return dp[n - 1];
}
int spaceOptimization(vector<int> &heights)
{
  int n = heights.size();

  int prev2 = 0;
  int prev1 = 0;

  for (int i = 1; i < n; i++)
  {
    int oneJump = prev1 + abs(heights[i] - heights[i - 1]);

    int twoJump = INT_MAX;

    if (i > 1)
    {
      twoJump = prev2 + abs(heights[i] - heights[i - 2]);
    }

    int current = min(oneJump, twoJump);

    prev2 = prev1;
    prev1 = current;
  }

  return prev1;
}

int main()
{
  vector<int> heights = {10, 20, 30, 10};

  // Recursion
  cout << "Recursion: ";
  cout << recursion(heights, heights.size() - 1) << endl;

  // Memoization
  vector<int> dp(heights.size(), -1);

  cout << "Memoization: ";
  cout << memoization(heights, heights.size() - 1, dp) << endl;

  // Tabulation
  cout << "Tabulation: ";
  cout << tabulation(heights) << endl;

  // Space Optimization
  cout << "Tabulation: ";
  cout << spaceOptimization(heights) << endl;

  return 0;
}