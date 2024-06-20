#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Helper function with memoization
int solve(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
  // Base case: when index is 0, return the maximum profit obtainable by repeatedly cutting rod into pieces of length 1
  if (ind == 0)
  {
    return N * price[0];
  }
  // If the subproblem has already been solved, return the stored value
  if (dp[ind][N] != -1)
    return dp[ind][N];

  // Do not cut the rod at this length, move to the next possible length
  int notTake = solve(ind - 1, N, price, dp);
  int take = INT_MIN;
  // If the current length of rod (ind + 1) is less than or equal to the remaining rod length
  if (ind + 1 <= N)
  {
    // Cut the rod at this length and solve for the remaining length
    take = price[ind] + solve(ind, N - (ind + 1), price, dp);
  }
  // Store the result in dp array and return the maximum profit obtained by either taking or not taking the current length
  return dp[ind][N] = max(take, notTake);
}

// Function to initialize the memoization table and call the solve function
int cutRod(vector<int> &price, int n)
{
  int m = price.size();
  // Initialize dp array with -1 to indicate unsolved subproblems
  vector<vector<int>> dp(m, vector<int>(n + 1, -1));
  // Call the solve function starting from the last index and the full length of the rod
  return solve(m - 1, n, price, dp);
}

// Driver code
int main()
{
  // Example price array where price[i] is the price of a rod of length i+1
  vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
  // Length of the rod
  int n = 8;
  // Create an instance of the Solution class and call the cutRod function
  int result = cutRod(price, n);
  // Print the maximum obtainable value
  cout << "Maximum obtainable value is: " << result << endl;

  return 0;
}
