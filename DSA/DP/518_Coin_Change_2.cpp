#include <iostream>
#include <vector>

using namespace std;
int solve(int index, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
  // Base case: if we're at the first coin
  if (index == 0)
  {
    // If amount is divisible by the coin value, we can form the amount with this coin
    return (amount % coins[0] == 0) ? 1 : 0;
  }

  // Check if the subproblem is already solved
  if (dp[index][amount] != -1)
    return dp[index][amount];

  // Option 1: Don't take the current coin
  int nottake = solve(index - 1, coins, amount, dp);

  // Option 2: Take the current coin (if it doesn't exceed the amount)
  int take = 0;
  if (coins[index] <= amount)
  {
    take = solve(index, coins, amount - coins[index], dp);
  }

  // Store the result in the dp array
  return dp[index][amount] = nottake + take;
}

int change(int amount, vector<int> &coins)
{
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
  return solve(n - 1, coins, amount, dp);
}
int main()
{
  // Test case
  vector<int> coins = {1, 2, 5};
  int amount = 5;

  int result = change(amount, coins);

  cout << "Number of ways to make change for " << amount << " is: " << result << endl;

  return 0;
}