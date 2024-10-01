#include <bits/stdc++.h>
using namespace std;

bool canArrange(vector<int> &arr, int k)
{
  vector<int> freq(k, 0); // Initialize a frequency array of size k

  // Calculate the frequency of each remainder when dividing the elements by k
  for (int num : arr)
  {
    int remainder = ((num % k) + k) % k; // This ensures positive remainders
    freq[remainder]++;
  }

  // Check if the number of elements with remainder 0 is even
  if (freq[0] % 2 != 0)
    return false; // Elements with remainder 0 must form pairs

  // Check pairs of remainders i and (k - i)
  for (int i = 1; i <= k / 2; i++)
  {
    if (freq[i] != freq[k - i])
      return false; // The count of remainders i and k-i must be the same
  }

  return true; // If all checks pass, the array can be arranged as required
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
  int k = 5;
  bool ans = canArrange(arr, k);
  cout << ans;
}