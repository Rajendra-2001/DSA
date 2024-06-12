#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int l = 0;               // Pointer for the next position of 0
    int m = 0;               // Pointer for the current element
    int h = nums.size() - 1; // Pointer for the next position of 2

    while (m <= h)
    {
      if (nums[m] == 0)
      {
        // Swap current element with the element at l and move both pointers forward
        swap(nums[l], nums[m]);
        l++;
        m++;
      }
      else if (nums[m] == 1)
      {
        // Move the m pointer forward when the element is 1
        m++;
      }
      else if (nums[m] == 2)
      {
        // Swap current element with the element at h and move h pointer backward
        swap(nums[m], nums[h]);
        h--;
      }
    }
  }
};
void printVector(const vector<int> &vec)
{
  for (int num : vec)
  {
    cout << num << " ";
  }
  cout << endl;
}

int main()
{
  Solution solution;

  // Test cases
  vector<vector<int>> testCases = {
      {2, 0, 2, 1, 1, 0},
      {2, 0, 1},
      {0},
      {1},
      {2},
      {2, 2, 2, 2},
      {0, 0, 0, 0},
      {1, 1, 1, 1},
      {2, 1, 2, 0, 1, 0, 2, 1, 0}};

  for (auto &testCase : testCases)
  {
    cout << "Before sorting: ";
    printVector(testCase);
    solution.sortColors(testCase);
    cout << "After sorting: ";
    printVector(testCase);
    cout << endl;
  }

  return 0;
}