#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums)
{
  int n = nums.size(), k = -1, l;

  // Find the largest index k such that nums[k] < nums[k+1]
  for (int i = n - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      k = i;
      break;
    }
  }

  if (k == -1)
  {
    // If no such index exists, reverse the entire sequence
    reverse(nums.begin(), nums.end());
  }
  else
  {
    // Find the largest index l such that nums[l] > nums[k]
    for (l = n - 1; l > k; l--)
    {
      if (nums[l] > nums[k])
      {
        break;
      }
    }

    // Swap nums[k] and nums[l]
    swap(nums[k], nums[l]);

    // Reverse the subsequence nums[k+1:]
    reverse(nums.begin() + k + 1, nums.end());
  }
}

int main()
{
  vector<int> nums = {1, 2, 3};

  cout << "Original vector: ";
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  nextPermutation(nums);

  cout << "Next permutation: ";
  for (int num : nums)
  {
    cout << num << " ";
  }
  cout << endl;

  // Add more test cases if needed
  vector<int> nums2 = {3, 2, 1};
  nextPermutation(nums2);
  cout << "Next permutation: ";
  for (int num : nums2)
  {
    cout << num << " ";
  }
  cout << endl;

  vector<int> nums3 = {1, 1, 5};
  nextPermutation(nums3);
  cout << "Next permutation: ";
  for (int num : nums3)
  {
    cout << num << " ";
  }
  cout << endl;

  vector<int> nums4 = {1};
  nextPermutation(nums4);
  cout << "Next permutation: ";
  for (int num : nums4)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}