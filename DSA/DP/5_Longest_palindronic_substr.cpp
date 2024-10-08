#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

// Memoization
bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp)
{
  if (i >= j)
    return true; // Base case: Single character or empty string
  if (dp[i][j] != -1)
    return dp[i][j]; // Return cached result

  if (s[i] == s[j])
  {
    dp[i][j] = isPalindrome(s, i + 1, j - 1, dp);
  }
  else
  {
    dp[i][j] = false;
  }

  return dp[i][j];
}

// Function to find the longest palindromic substring using memoization
string longestPalindromeMemo(string s)
{
  int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize memoization table

  int start = 0;
  int max_len = 0;

  // Iterate over all possible substrings
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (isPalindrome(s, i, j, dp))
      {
        if (max_len < j - i + 1)
        {
          max_len = j - i + 1;
          start = i;
        }
      }
    }
  }
  return s.substr(start, max_len); // Return the longest palindromic substring
}

// Tabulation

string longestPalindromeTab(string s)
{
  int n = s.length();
  if (n == 0)
    return "";

  vector<vector<bool>> dp(n, vector<bool>(n, false)); // Create a 2D table to store palindromic states
  int max_len = 1;                                    // Every single character is a palindrome of length 1
  int start = 0;                                      // Starting index of the longest palindromic substring

  // All substrings of length 1 are palindromes
  for (int i = 0; i < n; i++)
  {
    dp[i][i] = true;
  }

  // Check for palindromes of length 2
  for (int i = 0; i < n - 1; i++)
  {
    if (s[i] == s[i + 1])
    {
      dp[i][i + 1] = true;
      start = i;
      max_len = 2;
    }
  }

  // Check for palindromes of length 3 and greater
  for (int len = 3; len <= n; len++)
  {
    for (int i = 0; i < n - len + 1; i++)
    {
      int j = i + len - 1; // Ending index of the current substring

      // If the current substring is a palindrome
      if (s[i] == s[j] && dp[i + 1][j - 1])
      {
        dp[i][j] = true;

        if (len > max_len)
        {
          start = i;
          max_len = len;
        }
      }
    }
  }

  // Return the longest palindromic substring
  return s.substr(start, max_len);
}

int main()
{
  string s = "babababababaaaaaaaaaad";
  string result = longestPalindromeTab(s);
  cout << "Longest palindromic substring: " << result << endl; // Output: "bab" or "aba"
  return 0;
}
