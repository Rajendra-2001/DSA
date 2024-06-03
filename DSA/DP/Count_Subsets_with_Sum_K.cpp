#include <vector>
#include <iostream>

using namespace std;

#define MOD 1000000007

// Recursion
/*
int solve(int ind, int target, vector<int>& arr) {
    if (target == 0) return 1;
    if (ind == 0) return arr[ind] == target;
    int notTake = solve(ind - 1, target, arr);
    int take = 0;
    if (arr[ind] <= target) take = solve(ind - 1, target - arr[ind], arr);
    return take + notTake;
}
*/

// Memoization
/*
int helper(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return 1;
    if (ind == 0) return (arr[0] == target) ? 1 : 0;
    if (dp[ind][target] != -1) return dp[ind][target];
    int notTaken = helper(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target) taken = helper(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken + taken;
}

// Function to find the number of ways to achieve the target sum using the given array
int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    // Initialize memoization table with -1 (indicating uncomputed values)
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    // Call the recursive function with the last index and target sum
    return helper(n - 1, k, arr, dp);
}
*/

// Dynamic Programming
int findWays(vector<int> &arr, int k)
{
  int n = arr.size();
  // Initialize dp table with 0
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

  // Base case: If the array is empty and the sum is 0 then there always exists a single subset with sum 0
  dp[0][0] = 1;

  // Fill the dp table
  for (int index = 1; index <= n; ++index)
  {
    for (int currSum = 0; currSum <= k; ++currSum)
    {
      int currSkip = dp[index - 1][currSum];
      int currTake = 0;
      if (arr[index - 1] <= currSum)
      {
        currTake = dp[index - 1][currSum - arr[index - 1]];
      }
      dp[index][currSum] = (currTake + currSkip) % MOD;
    }
  }

  // Return the count of all the subsets with sum equal to the given sum
  return dp[n][k];
}

// Driver code
int main()
{
  vector<int> arr = {1, 2, 3, 4}; // Example input
  int k = 5;
  int result = findWays(arr, k);
  cout << "Number of ways to achieve the target sum is: " << result << endl;

  // Additional example
  vector<int> arr2 = {1, 2, 3, 4, 5};
  k = 10;
  result = findWays(arr2, k);
  cout << "Number of ways to achieve the target sum is: " << result << endl;

  return 0;
}
