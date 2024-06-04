#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    unordered_map<char, int> count;
    int result = 0;
    for (char c : s)
      count[c]++;
    bool odd_ = false;
    for (auto &i : count)
    {
      if (i.second % 2 == 0)
        result += i.second;
      else
      {
        odd_ = true;
        result += i.second - 1;
      }
    }
    if (odd_ == true)
      result++;
    return result;
  }
};

int main()
{
  Solution solution;

  // Test cases
  vector<string> testCases = {
      "abccccdd",
      "a",
      "bb",
      "ab",
      "abc",
      "aaa",
      "Aa",
      "aaAA",
      "abAB",
      "abccccddDD"};

  for (const auto &testCase : testCases)
  {
    string s = testCase;
    int result = solution.longestPalindrome(s);
    cout << "s: \"" << s << "\" -> Longest Palindrome Length: " << result << endl;
  }

  return 0;
}
