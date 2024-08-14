#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the k-th smallest distance pair
int smallestDistancePair(vector<int> &nums, int k)
{
  int n = nums.size();
  int max_E = *max_element(nums.begin(), nums.end());

  vector<int> vec(max_E + 1, 0);

  // Count the frequency of each possible distance
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int d = abs(nums[i] - nums[j]);
      vec[d]++;
    }
  }

  // Find the k-th smallest distance
  for (int d = 0; d <= max_E; d++)
  {
    k -= vec[d];
    if (k <= 0)
      return d;
  }

  return -1; // This should never be reached if the input is valid
}

// Driver code
int main()
{
  vector<int> nums = {1, 3, 1};
  int k = 2;

  int result = smallestDistancePair(nums, k);

  cout << "The " << k << "-th smallest distance pair is: " << result << endl;

  return 0;
}
