#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int longestSubarray(vector<int> &nums)
{
  ios::sync_with_stdio(false);
  cout.tie(nullptr);

  // Step 1: Find the maximum element in the array
  int maxE = *max_element(nums.begin(), nums.end());

  // Step 2: Traverse the array and find the longest subarray of maxE
  int count = 0; // To store the longest subarray length
  int curr = 0;  // To store the current subarray length

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == maxE)
    {
      curr++; // If current element is maxE, increment the current length
    }
    else
    {
      count = max(count, curr); // Update count if current subarray is longer
      curr = 0;                 // Reset current length
    }
  }

  // Step 3: One final check to update count in case the longest subarray ends at the end
  count = max(count, curr);

  return count;
}

int main()
{
  vector<int> nums = {1, 2, 5, 5, 5, 3, 2};
  cout << "Length of longest subarray of maximum element: " << longestSubarray(nums) << endl;
  return 0;
}
