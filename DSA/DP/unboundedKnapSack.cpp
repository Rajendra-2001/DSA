#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
  // Base case
  if (ind == 0)
  {
    return (W / weight[0]) * profit[0];
  }

  // If the result is already computed, return it
  if (dp[ind][W] != -1)
    return dp[ind][W];

  int notTake = solve(ind - 1, W, profit, weight, dp);
  int take = INT_MIN;

  if (weight[ind] <= W)
  {
    take = profit[ind] + solve(ind, W - weight[ind], profit, weight, dp);
  }

  return dp[ind][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
  // Initialize a DP table
  vector<vector<int>> dp(n, vector<int>(W + 1, -1));
  return solve(n - 1, W, profit, weight, dp);
}
