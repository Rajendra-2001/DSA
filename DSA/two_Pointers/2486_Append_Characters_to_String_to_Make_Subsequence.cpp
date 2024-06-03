#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  int appendCharacters(string s, string t)
  {
    int s_index = 0, t_index = 0;
    int s_length = s.length(), t_length = t.length();

    while (s_index < s_length && t_index < t_length)
    {
      if (s[s_index] == t[t_index])
      {
        t_index++;
      }
      s_index++;
    }

    return t_length - t_index;
  }
};

int main()
{
  Solution solution;

  // Test cases
  vector<pair<string, string>> testCases = {
      {"abc", "abc"},
      {"abc", "abcd"},
      {"abc", "ab"},
      {"abc", "a"},
      {"abc", "bc"},
      {"abc", "c"},
      {"abc", "def"},
      {"abc", "bce"},
      {"", "a"},
      {"a", ""}};

  for (const auto &testCase : testCases)
  {
    string s = testCase.first;
    string t = testCase.second;
    int result = solution.appendCharacters(s, t);
    cout << "s: \"" << s << "\", t: \"" << t << "\" -> Result: " << result << endl;
  }

  return 0;
}
