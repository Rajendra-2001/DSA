#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool checkSubarraySum(vector<int> &nums, int k)
  {
    int prefSum = 0;            // Variable to store the prefix sum
    unordered_map<int, int> mp; // HashMap to store the remainder of the prefix sum and its index

    for (int i = 0; i < nums.size(); i++)
    {
      prefSum += nums[i]; // Add the current element to the prefix sum
      prefSum %= k;       // Take the modulo k of the prefix sum

      if (prefSum == 0 && i > 0)
        return true; // If the prefix sum modulo k is 0 and there are at least 2 elements, return true

      if (mp.find(prefSum) != mp.end())
      { // If the remainder is found in the HashMap
        if (i - mp[prefSum] > 1)
          return true; // Check if the subarray length is at least 2
      }
      else
      {
        mp[prefSum] = i; // Store the remainder and its index in the HashMap
      }
    }

    return false; // If no valid subarray is found, return false
  }
};

int main()
{
  Solution solution;

  vector<int> nums1 = {23, 2, 4, 6, 7};
  int k1 = 6;
  cout << "Test case 1: " << (solution.checkSubarraySum(nums1, k1) ? "True" : "False") << endl;

  vector<int> nums2 = {23, 2, 6, 4, 7};
  int k2 = 6;
  cout << "Test case 2: " << (solution.checkSubarraySum(nums2, k2) ? "True" : "False") << endl;

  vector<int> nums3 = {23, 2, 6, 4, 7};
  int k3 = 13;
  cout << "Test case 3: " << (solution.checkSubarraySum(nums3, k3) ? "True" : "False") << endl;

  vector<int> nums4 = {1, 2, 3};
  int k4 = 5;
  cout << "Test case 4: " << (solution.checkSubarraySum(nums4, k4) ? "True" : "False") << endl;

  vector<int> nums5 = {0, 0};
  int k5 = 1;
  cout << "Test case 5: " << (solution.checkSubarraySum(nums5, k5) ? "True" : "False") << endl;

  return 0;
}
