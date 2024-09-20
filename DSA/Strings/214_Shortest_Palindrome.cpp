#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int end)
{
  int i = 0, j = end;
  while (i < j)
  {
    if (s[i] != s[j])
      return false;
    i++;
    j--;
  }
  return true;
}

string shortestPalindrome(string s)
{
  if (s.empty())
    return s; // Edge case for empty string

  int n = s.size();
  if (isPalindrome(s, s.size() - 1))
    return s;
  // Step 1: Find the longest palindromic prefix
  int longestPrefixPalin = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (isPalindrome(s, i))
    {
      longestPrefixPalin = i + 1; // Store the length of the palindrome
      break;
    }
  }

  // Step 2: Reverse the remaining non-palindromic part and prepend it
  string suffix = s.substr(longestPrefixPalin); // Non-palindromic part
  reverse(suffix.begin(), suffix.end());        // Reverse the suffix

  return suffix + s; // Prepend the reversed suffix and return the result
}

int main()
{
  string s = "abcde";
  cout << shortestPalindrome(s);
}