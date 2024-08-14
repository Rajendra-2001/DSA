#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find combinations
void comb(int ind, int target, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds)
{
  if (target == 0)
  {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < nums.size(); i++)
  {
    if (i > ind && nums[i] == nums[i - 1])
      continue; // Skip duplicates
    if (nums[i] > target)
      break; // No point in continuing if the number is greater than the target
    ds.push_back(nums[i]);
    comb(i + 1, target - nums[i], nums, ans, ds);
    ds.pop_back(); // Backtrack to explore other possibilities
  }
}

// Function to get unique combinations that sum up to the target
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> ds;
  sort(candidates.begin(), candidates.end()); // Sort to handle duplicates and for early stopping
  comb(0, target, candidates, ans, ds);
  return ans;
}

// Driver code
int main()
{
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  vector<vector<int>> result = combinationSum2(candidates, target);

  cout << "Unique combinations that sum up to " << target << " are:" << endl;
  for (const auto &combination : result)
  {
    cout << "[ ";
    for (int num : combination)
    {
      cout << num << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
