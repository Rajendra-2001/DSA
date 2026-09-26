#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------
// 1. RECURSION
// --------------------------------------------------

int recSol(vector<int> &heights, int k, int idx)
{
  if (idx == 0)
    return 0;

  int minStep = INT_MAX;

  for (int j = 1; j <= k; j++)
  {
    if (idx - j >= 0)
    {
      int jump = recSol(heights, k, idx - j) + abs(heights[idx] - heights[idx - j]);

      minStep = min(minStep, jump);
    }
  }

  return minStep;
}

// --------------------------------------------------
// 2. MEMOIZATION
// --------------------------------------------------

int memoSol(vector<int> &heights, int k, int idx, vector<int> &dp)
{
  if (idx == 0)
    return 0;

  if (dp[idx] != -1)
    return dp[idx];

  int minStep = INT_MAX;

  for (int j = 1; j <= k; j++)
  {
    if (idx - j >= 0)
    {
      int jump = memoSol(heights, k, idx - j, dp) + abs(heights[idx] - heights[idx - j]);

      minStep = min(minStep, jump);
    }
  }

  return dp[idx] = minStep;
}

// --------------------------------------------------
// 3. TABULATION
// --------------------------------------------------

int tabulationSol(vector<int> &heights, int k)
{
  int n = heights.size();

  vector<int> dp(n, INT_MAX);

  dp[0] = 0;

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= k; j++)
    {
      if (i - j >= 0)
      {
        int jump = dp[i - j] + abs(heights[i] - heights[i - j]);

        dp[i] = min(dp[i], jump);
      }
    }
  }

  return dp[n - 1];
}

// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main()
{
  vector<int> heights = {10, 30, 40, 20, 50};
  int k = 3;

  int n = heights.size();

  // Recursion
  int ans1 = recSol(heights, k, n - 1);

  // Memoization
  vector<int> dp(n, -1);
  int ans2 = memoSol(heights, k, n - 1, dp);

  // Tabulation
  int ans3 = tabulationSol(heights, k);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;

  return 0;
}