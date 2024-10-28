#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int search(int idx, int n, vector<int> &nums, unordered_map<int, int> &memo)
{
  if (memo.count(idx))
    return memo[idx]; // Use memoization to avoid redundant calculations

  int count = 1;                      // Each number is a sequence of at least one (itself)
  int target = nums[idx] * nums[idx]; // Look for this square

  // Binary search for the target square in the sorted array
  for (int i = idx + 1; i < n; ++i)
  {
    if (nums[i] == target)
    {
      count += search(i, n, nums, memo); // Recursive call with the found index
      break;                             // Stop after finding the square
    }
  }
  return memo[idx] = count; // Memoize and return result
}

int longestSquareStreak(vector<int> &nums)
{
  int n = nums.size();
  if (n == 0)
    return -1;

  sort(nums.begin(), nums.end()); // Sort to ensure we can search for squares
  unordered_map<int, int> memo;   // Memoization for optimization
  int max_streak = 0;

  for (int i = 0; i < n; i++)
  {
    int squareRootBound = sqrt(nums.back());
    if (nums[i] <= squareRootBound)
    {
      max_streak = max(max_streak, search(i, n, nums, memo)); // Update max streak
    }
  }

  return max_streak > 1 ? max_streak : -1; // Return -1 if no valid streak found
}
