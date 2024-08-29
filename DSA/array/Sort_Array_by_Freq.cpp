#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Custom comparator function to sort pairs based on frequency and value
static bool func(pair<int, int> p1, pair<int, int> p2)
{
  // If the frequencies are the same, sort by value in ascending order
  if (p1.second == p2.second)
  {
    return p1.first < p2.first;
  }
  // Otherwise, sort by frequency in descending order
  return p1.second > p2.second;
}

vector<int> sortByFreq(vector<int> &arr)
{
  unordered_map<int, int> mpp;

  // Count the frequency of each element in the array
  for (int it : arr)
  {
    mpp[it]++;
  }

  vector<pair<int, int>> vec;

  // Convert the map to a vector of pairs
  for (auto it : mpp)
  {
    vec.push_back({it.first, it.second});
  }

  // Sort the vector based on the custom comparator
  sort(vec.begin(), vec.end(), func);

  vector<int> ans;

  // Add the sorted elements to the answer vector based on their frequency
  for (auto it : vec)
  {
    int cnt = it.second;
    while (cnt--)
    {
      ans.push_back(it.first);
    }
  }

  return ans;
}

int main()
{
  vector<int> arr = {5, 3, 5, 2, 8, 2, 8, 8};

  vector<int> sortedArr = sortByFreq(arr);

  // Print the sorted array
  cout << "Array sorted by frequency and value: ";
  for (int num : sortedArr)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
