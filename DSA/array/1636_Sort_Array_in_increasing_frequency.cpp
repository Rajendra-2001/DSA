#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
  // Create a frequency map
  unordered_map<int, int> freq;

  // Count the frequency of each number in the input vector
  for (int num : nums)
  {
    freq[num]++;
  }

  // Sort the numbers based on frequency, and by value in descending order if frequencies are equal
  sort(nums.begin(), nums.end(), [&](int n1, int n2)
       {
        if (freq[n1] != freq[n2]) {
            return freq[n1] < freq[n2]; // Ascending order of frequency
        } else {
            return n2 < n1; // Descending order of value
        } });

  return nums;
}

// Driver code
int main()
{
  vector<int> nums = {1, 1, 2, 2, 2, 3};

  vector<int> sortedNums = frequencySort(nums);

  cout << "Sorted numbers by frequency and value:" << endl;
  for (int num : sortedNums)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
