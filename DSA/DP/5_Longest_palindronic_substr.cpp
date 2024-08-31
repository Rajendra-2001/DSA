#include <iostream>
#include <string>

using namespace std;
bool solve(string &s, int i, int j)
{
  if (i >= j)
    return true;
  if (s[i] == s[j])
  {
    return solve(s, i + 1, j - 1);
  }
  return false;
}

string longestPalindrome(string s)
{
  int sp = 0;
  int max_len = 0; // Corrected: Initialize to 0 since we are checking lengths

  for (int i = 0; i < s.length(); i++)
  {
    for (int j = i; j < s.length(); j++)
    {
      if (solve(s, i, j))
      {
        if (max_len < j - i + 1)
        { // Corrected: Ensure correct comparison
          max_len = j - i + 1;
          sp = i;
        }
      }
    }
  }
  return s.substr(sp, max_len);
}

int main()
{
  string s = "babababababaaaaaaaaaad";
  string result = longestPalindrome(s);
  cout << "Longest palindromic substring: " << result << endl; // Output: "bab" or "aba"
  return 0;
}
