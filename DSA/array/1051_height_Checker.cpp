#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int heightChecker(vector<int> &heights)
  {
    // Create a copy of the original heights vector
    vector<int> ans = heights;

    // Sort the copied vector
    sort(ans.begin(), ans.end());

    int cnt = 0; // Counter to count the number of mismatches

    // Compare each element of the sorted vector with the original vector
    for (int i = 0; i < ans.size(); i++)
    {
      if (ans[i] != heights[i])
      {
        cnt++; // Increment the counter if there is a mismatch
      }
    }

    // Return the count of mismatches
    return cnt;
  }
};

int main()
{
  Solution solution;

  vector<int> heights1 = {1, 1, 4, 2, 1, 3};
  cout << "Test case 1: " << solution.heightChecker(heights1) << endl; // Expected output: 3

  vector<int> heights2 = {5, 1, 2, 3, 4};
  cout << "Test case 2: " << solution.heightChecker(heights2) << endl; // Expected output: 5

  vector<int> heights3 = {1, 2, 3, 4, 5};
  cout << "Test case 3: " << solution.heightChecker(heights3) << endl; // Expected output: 0

  return 0;
}
