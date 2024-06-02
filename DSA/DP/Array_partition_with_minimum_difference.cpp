#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int minSubsetSumDifference(vector<int> &nums, int n)
{
  int totalSum = 0;
  int minNum = INT_MAX, maxNum = INT_MIN;

  // Find the range of numbers in nums
  for (int num : nums)
  {
    totalSum += num;
    minNum = min(minNum, num);
    maxNum = max(maxNum, num);
  }

  int range = maxNum - minNum;

  // We will offset all numbers to be non-negative
  int offset = -minNum;
  int target = totalSum + n * offset; // new target sum after offset

  vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

  // Initialize dp table
  dp[0][nums[0] + offset] = true;
  for (int i = 0; i < n; ++i)
    dp[i][offset] = true; // zero sum is possible with empty subset

  // Fill the dp table
  for (int ind = 1; ind < n; ++ind)
  {
    for (int t = 0; t <= target; ++t)
    {
      bool notTake = dp[ind - 1][t];
      bool take = false;
      if (t >= nums[ind] + offset)
      {
        take = dp[ind - 1][t - (nums[ind] + offset)];
      }
      dp[ind][t] = notTake || take;
    }
  }

  int mini = INT_MAX;
  for (int s1 = 0; s1 <= totalSum; ++s1)
  {
    if (dp[n - 1][s1 + n * offset])
    {
      int s2 = totalSum - s1;
      mini = min(mini, abs(s2 - s1));
    }
  }

  return mini;
}

// Driver code
int main()
{
  vector<int> nums = {1, 2, 3, 9}; // Example input
  int n = nums.size();
  int result = minSubsetSumDifference(nums, n);
  cout << "The minimum subset sum difference is: " << result << endl;

  // Another example with negative numbers
  vector<int> nums2 = {-1, 2, -3, 4, 5};
  n = nums2.size();
  result = minSubsetSumDifference(nums2, n);
  cout << "The minimum subset sum difference is: " << result << endl;

  return 0;
}
