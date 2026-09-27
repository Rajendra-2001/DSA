#include <bits/stdc++.h>
using namespace std;

// ==================================================
// 1. RECURSION
// ==================================================

int recSolve(vector<int> &nums, int n)
{
  if (n == 0)
    return 0;

  if (n == 1)
    return nums[0];

  int take = nums[n - 1] + recSolve(nums, n - 2);

  int notTake = recSolve(nums, n - 1);

  return max(take, notTake);
}

// ==================================================
// 2. MEMOIZATION
// ==================================================

int memoSolve(vector<int> &nums, int n, vector<int> &dp)
{
  if (n == 0)
    return 0;

  if (n == 1)
    return nums[0];

  if (dp[n] != -1)
    return dp[n];

  int take = nums[n - 1] + memoSolve(nums, n - 2, dp);

  int notTake = memoSolve(nums, n - 1, dp);

  return dp[n] = max(take, notTake);
}

// ==================================================
// 3. TABULATION
// ==================================================

int tabulationSolve(vector<int> &nums)
{
  int n = nums.size();

  vector<int> dp(n + 1, -1);

  dp[0] = 0;
  dp[1] = nums[0];

  for (int i = 2; i <= n; i++)
  {
    int take = nums[i - 1] + dp[i - 2];

    int notTake = dp[i - 1];

    dp[i] = max(take, notTake);
  }

  return dp[n];
}

// ==================================================
// 4. SPACE OPTIMIZATION
// ==================================================

int spaceOptimizedSolve(vector<int> &nums)
{
  int n = nums.size();

  int prev = 0;
  int prev1 = nums[0];

  for (int i = 2; i <= n; i++)
  {
    int take = nums[i - 1] + prev;

    int notTake = prev1;

    int curr = max(take, notTake);

    prev = prev1;
    prev1 = curr;
  }

  return prev1;
}

// ==================================================
// MAIN
// ==================================================

int main()
{
  vector<int> nums = {2, 7, 9, 3, 1};

  int n = nums.size();

  // 1. Recursion
  int ans1 = recSolve(nums, n);

  // 2. Memoization
  vector<int> dp(n + 1, -1);
  int ans2 = memoSolve(nums, n, dp);

  // 3. Tabulation
  int ans3 = tabulationSolve(nums);

  // 4. Space Optimization
  int ans4 = spaceOptimizedSolve(nums);

  cout << "Recursion: " << ans1 << endl;
  cout << "Memoization: " << ans2 << endl;
  cout << "Tabulation: " << ans3 << endl;
  cout << "Space Optimization: " << ans4 << endl;

  return 0;
}