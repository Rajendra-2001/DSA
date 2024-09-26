#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
  if (index >= nums.size())
  {
    ans.push_back(nums);
    return;
  }
  for (int j = index; j < nums.size(); j++)
  {
    swap(nums[index], nums[j]);  // Swap to generate a new permutation
    solve(nums, ans, index + 1); // Recurse to generate permutations for the remaining elements
    // No need to swap back, as nums is passed by value, not reference
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  int index = 0;
  solve(nums, ans, index); // Start solving from index 0
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = permute(nums);

  // Print all permutations
  for (auto &perm : ans)
  {
    for (int num : perm)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
