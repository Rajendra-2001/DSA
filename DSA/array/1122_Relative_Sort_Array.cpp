#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
  {
    int freq[1001] = {0}, m = 0, i = 0;
    for (int num : arr1)
    {
      freq[num]++;
      m = max(m, num);
    }
    for (int num : arr2)
      while (freq[num]--)
        arr1[i++] = num;
    for (int j = 0; j <= m; j++)
      while (freq[j]-- > 0)
        arr1[i++] = j;
    return arr1;
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
  vector<pair<vector<int>, vector<int>>> testCases = {
      {{2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, {2, 1, 4, 3, 9, 6}},
      {{28, 6, 22, 8, 44, 17}, {22, 28, 8, 6}},
      {{}, {1, 2, 3}},
      {{1, 2, 3}, {}},
      {{5, 5, 5, 1, 2, 3}, {5}},
      {{1, 2, 3, 4, 5}, {4, 2}},
      {{1, 1, 1, 2, 2, 2}, {2, 1}}};

  for (auto &testCase : testCases)
  {
    vector<int> arr1 = testCase.first;
    vector<int> arr2 = testCase.second;
    vector<int> result = solution.relativeSortArray(arr1, arr2);
    cout << "arr1: ";
    printVector(testCase.first);
    cout << "arr2: ";
    printVector(testCase.second);
    cout << "Result: ";
    printVector(result);
    cout << endl;
  }

  return 0;
}
