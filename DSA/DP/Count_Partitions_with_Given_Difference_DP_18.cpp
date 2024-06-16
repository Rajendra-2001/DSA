#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Helper function for the recursive solution with memoization
int solve(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
  // Base case: if target is achieved with no elements left
  if (index == 0)
  {
    if (target == 0 && arr[0] == 0)
      return 2; // Consider both taking and not taking the 0
    if (target == 0 || target == arr[0])
      return 1;
    return 0;
  }

  // Return cached result if available
  if (dp[index][target] != -1)
    return dp[index][target];

  // Case of not taking the current element
  int notTake = solve(index - 1, target, arr, dp);

  // Case of taking the current element
  int take = 0;
  if (arr[index] <= target)
  {
    take = solve(index - 1, target - arr[index], arr, dp);
  }

  // Save and return the result
  return dp[index][target] = (take + notTake) % MOD;
}

int countPartitions(int n, int d, vector<int> &arr)
{
  int totalSum = accumulate(arr.begin(), arr.end(), 0);

  // Check if it's possible to partition the array with the given difference
  if (totalSum < d || (totalSum - d) % 2 != 0)
    return 0;

  int target = (totalSum - d) / 2;

  // Initialize memoization table with -1
  vector<vector<int>> dp(n, vector<int>(target + 1, -1));

  return solve(n - 1, target, arr, dp);
}

int main()
{
  vector<int> arr = {1, 2, 3, 4};
  int n = arr.size();
  int d = 1;
  cout << "Number of partitions: " << countPartitions(n, d, arr) << endl;
  return 0;
}
