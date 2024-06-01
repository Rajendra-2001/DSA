#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
// Recursion

// bool solve(int ind,int target,vector<int>&arr)
// {
//     if(target==0) return true;
//     if(ind ==0 ) return (target==arr[0]);

//     bool notTake=solve(ind-1,target,arr);
//     bool Take=false;
//     if(arr[ind]<=target) Take=solve(ind-1,target-arr[ind],arr);
//     return Take | notTake ;
// }

// Memoization

// bool solve(int ind,int target,vector<int>&arr, vector<vector<int>>&dp)
// {
//     if(target==0) return true;
//     if(ind ==0 ) return (target==arr[0]);
//     if(dp[ind][target]!=-1 ) return dp[ind][target];
//     bool notTake=solve(ind-1,target,arr,dp);
//     bool Take=false;
//     if(arr[ind]<=target) Take=solve(ind-1,target-arr[ind],arr,dp);
//     return dp[ind][target]= Take | notTake ;
// }

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // Write your code here
  // vector<vector<int>>dp(n,vector<int>(k+1,-1)); For Memoization
  // Create a 2D DP array with default values as false
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

  // Tabulation
  //  Base case: A sum of 0 can always be achieved with an empty subset
  for (int i = 0; i < n; ++i)
  {
    dp[i][0] = true;
  }

  // If the first element is equal to k, set dp[0][arr[0]] to true
  if (arr[0] == k)
  {
    dp[0][arr[0]] = true;
  }

  // Fill the DP table
  for (int ind = 1; ind < n; ++ind)
  {
    for (int target = 1; target <= k; ++target)
    {
      // Option 1: Not take the current element
      bool notTake = dp[ind - 1][target];

      // Option 2: Take the current element, if it does not exceed the target
      bool take = false;
      if (arr[ind] <= target)
      {
        take = dp[ind - 1][target - arr[ind]];
      }

      // Update the DP table
      dp[ind][target] = take || notTake;
    }
  }

  // The answer will be in dp[n-1][k]
  return dp[n - 1][k];
  // return solve(n-1,k,arr,dp);
}

int main()
{
  // Example usage
  vector<int> arr = {3, 34, 4, 12, 5, 2};
  int k = 9;
  int n = arr.size();

  bool result = subsetSumToK(n, k, arr);

  if (result)
  {
    cout << "There exists a subset with sum " << k << endl;
  }
  else
  {
    cout << "No subset with sum " << k << " exists" << endl;
  }

  return 0;
}