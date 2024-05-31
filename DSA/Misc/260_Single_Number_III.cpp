#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    vector<int> ans;
    map<int, int> mp;

    // Count the frequency of each number
    for (auto &i : nums)
    {
      mp[i]++;
    }

    // Find all numbers that appear exactly once
    for (auto &i : mp)
    {
      if (i.second == 1)
      {
        ans.push_back(i.first);
      }
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1}; // Example input
  vector<int> result = solution.singleNumber(nums);

  cout << "Numbers that appear exactly once: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
