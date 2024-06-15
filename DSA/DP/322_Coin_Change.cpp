#include <bits/stdc++.h>
using namespace std;
int solve(int ind, vector<int> &coins, int target, vector<vector<int>> &dp)
{
  // Base cases
  if (ind < 0)
    return INT_MAX - 1; // No more coins to use and target not met
  if (target == 0)
    return 0; // No coins needed to make 0 amount
  if (dp[ind][target] != -1)
    return dp[ind][target];
  // Case of not taking the current coin
  int notTake = solve(ind - 1, coins, target, dp);

  // Case of taking the current coin
  int take = INT_MAX;
  if (coins[ind] <= target)
  {
    take = 1 + solve(ind, coins, target - coins[ind], dp);
  }

  // Return the minimum of taking or not taking the coin
  return dp[ind][target] = min(take, notTake);
}

int coinChange(vector<int> &coins, int amount)
{
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  int ans = solve(n - 1, coins, amount, dp);
  if (ans >= INT_MAX - 1)
    return -1; // If no solution found, return -1
  return ans;
}
int main()
{
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
  return 0;
}