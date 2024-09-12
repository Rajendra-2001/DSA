#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words)
{
  vector<int> freq(26, 0); // Frequency array for allowed characters

  // Mark the allowed characters in the frequency array
  for (char c : allowed)
  {
    freq[c - 'a'] = 1; // Mark character as allowed
  }

  int count = 0; // To count consistent strings

  // Iterate over each word in the words list
  for (const string &s : words)
  {
    bool found = true; // Assume the word is consistent

    // Check each character in the word
    for (char c : s)
    {
      // If the character is not allowed, mark the word as inconsistent
      if (freq[c - 'a'] != 1)
      {
        found = false;
        break;
      }
    }

    // If the word is consistent, increment the count
    if (found)
      count++;
  }

  return count;
}

int main()
{
  vector<string> st = {"a", "b", "c", "d", "abc", "ab"};
  string all = "abc";
  int ans = countConsistentStrings(all, st);
  cout << ans;
}