#include <bits/stdc++.h>

using namespace std;

int solve(int ind, int W, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
  // Base case
  if (ind == 0)
  {
    return (W >= weight[0]) ? value[0] : 0;
  }

  // Check if the result is already computed
  if (dp[ind][W] != -1)
  {
    return dp[ind][W];
  }

  // Case of not taking the current item
  int notTake = solve(ind - 1, W, weight, value, dp);

  // Case of taking the current item
  int take = INT_MIN;
  if (weight[ind] <= W)
  {
    take = value[ind] + solve(ind - 1, W - weight[ind], weight, value, dp);
  }

  // Store the result in dp array and return
  return dp[ind][W] = max(take, notTake);
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
  // Create a 2D dp vector initialized with -1
  vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

  // Start the recursive knapsack function from the last index
  return solve(n - 1, maxWeight, weight, value, dp);
}
