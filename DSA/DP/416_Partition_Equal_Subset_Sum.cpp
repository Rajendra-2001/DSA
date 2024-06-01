#include <iostream>
#include <vector>
using namespace std;

// Recursion
//  bool solve(int ind, vector<int>& arr, int target) {
//      if (target == 0) return true; // If target is reached
//      if (ind < 0 || target < 0) return false; // If no more elements or target becomes negative
//      // Not take the current element
//      bool nottake = solve(ind - 1, arr, target);
//      // Take the current element
//      bool take = false;
//      if (arr[ind] <= target) {
//          take = solve(ind - 1, arr, target - arr[ind]);
//      }
//      return take || nottake;
//  }

// Memoization

// bool solve(int ind, vector<int> &arr, int target, vector<vector<int>> &dp)
// {
//   if (target == 0)
//     return true; // If target is reached
//   if (ind < 0 || target < 0)
//     return false; // If no more elements or target becomes negative
//                   // Not take the current element
//   if (dp[ind][target] != -1)
//     return dp[ind][target];
//   bool nottake = solve(ind - 1, arr, target, dp);
//   // Take the current element
//   bool take = false;
//   if (arr[ind] <= target)
//   {
//     take = solve(ind - 1, arr, target - arr[ind], dp);
//   }
//   return dp[ind][target] = take | nottake;
// }

// bool canPartition(vector<int> &arr, int n)
// {
//   int sum = 0;
//   for (auto &i : arr)
//     sum += i;
//   // If the total sum is odd, it can't be partitioned into two equal subsets
//   if (sum % 2 != 0)
//     return false;
//   int target = sum / 2;
//   vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//   return solve(n - 1, arr, target, dp);
// }

// Tabulation

bool canPartition(vector<int> &arr)
{
  int sum = 0;
  int n = arr.size();

  for (auto &i : arr)
    sum += i;
  // If the total sum is odd, it can't be partitioned into two equal subsets
  if (sum % 2 != 0)
    return false;

  int target = sum / 2;

  // Initialize dp table with false. dp[i][j] will be true if a subset with sum j can be formed from the first i elements.
  vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

  // If target is 0, we can always form the subset with sum 0 by taking no elements.
  for (int ind = 0; ind < n; ind++)
    dp[ind][0] = true;

  // With only the first element, we can form a subset with sum arr[0] if it is within the target.
  if (arr[0] <= target)
    dp[0][arr[0]] = true;

  // Fill the dp table
  for (int ind = 1; ind < n; ind++)
  {
    for (int j = 1; j <= target; j++)
    { // Fix: loop should run until target (inclusive)
      bool notTake = dp[ind - 1][j];
      bool take = false;
      if (arr[ind] <= j)
      { // Fix: condition should be arr[ind] <= j
        take = dp[ind - 1][j - arr[ind]];
      }
      dp[ind][j] = take || notTake;
    }
  }

  return dp[n - 1][target];
}

int main()
{
  vector<int> arr = {1, 5, 11, 5};

  if (canPartition(arr))
  {
    cout << "The array can be partitioned into two subsets with equal sum." << endl;
  }
  else
  {
    cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
  }

  return 0;
}
