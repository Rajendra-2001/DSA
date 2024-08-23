#include <vector>
#include <numeric>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
int minSwaps(std::vector<int> &nums)
{
  int n = nums.size();

  // Step 1: Create a circular array by repeating the original array
  std::vector<int> temp(2 * n);
  for (int i = 0; i < 2 * n; i++)
  {
    temp[i] = nums[i % n];
  }

  // Step 2: Calculate the total number of 1s in the original array
  int totalOnes = std::accumulate(nums.begin(), nums.end(), 0);

  // Step 3: Initialize variables to track the current count of 1s in the window
  int currOnes = 0, maxCount = 0;
  int i = 0, j = 0;

  // Step 4: Use a sliding window to find the maximum number of 1s in any subarray of size `totalOnes`
  while (j < 2 * n)
  {
    if (temp[j] == 1)
      currOnes++; // Increment the count of 1s for the current window

    if (j - i + 1 > totalOnes)
    { // If window size exceeds `totalOnes`
      if (temp[i] == 1)
        currOnes--; // Decrement the count of 1s as the left element moves out of the window
      i++;          // Slide the window to the right
    }

    maxCount = std::max(maxCount, currOnes); // Track the maximum count of 1s in any window
    j++;                                     // Move to the next element
  }

  // Step 5: The result is the difference between total 1s and the maximum count of 1s found in any window
  return totalOnes - maxCount;
}
int main()
{
  // Example usage
  std::vector<int> nums = {1, 0, 1, 0, 1};
  std::cout << "Minimum swaps required: " << minSwaps(nums) << std::endl;

  return 0;
}