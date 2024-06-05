#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  void fillColor(const string &word, int count[26])
  {
    for (auto &ch : word)
    {
      count[ch - 'a']++;
    }
  }

  vector<string> commonChars(vector<string> &words)
  {
    int n = words.size();
    if (n == 0)
      return {};

    int count[26] = {0};
    fillColor(words[0], count); // Initialize count with the first word's frequencies

    for (int i = 1; i < n; i++)
    {
      int temp[26] = {0};
      fillColor(words[i], temp);

      for (int j = 0; j < 26; j++)
      {
        count[j] = min(count[j], temp[j]);
      }
    }

    vector<string> ans;
    for (int i = 0; i < 26; i++)
    {
      while (count[i] > 0)
      {
        ans.push_back(string(1, i + 'a'));
        count[i]--;
      }
    }

    return ans;
  }
};

int main()
{
  Solution solution;

  vector<string> words1 = {"bella", "label", "roller"};
  vector<string> result1 = solution.commonChars(words1);
  cout << "Common characters in [bella, label, roller]: ";
  for (const string &s : result1)
  {
    cout << s << " ";
  }
  cout << endl;

  vector<string> words2 = {"cool", "lock", "cook"};
  vector<string> result2 = solution.commonChars(words2);
  cout << "Common characters in [cool, lock, cook]: ";
  for (const string &s : result2)
  {
    cout << s << " ";
  }
  cout << endl;

  // Add more test cases as needed
  vector<string> words3 = {"abc", "bca", "cab"};
  vector<string> result3 = solution.commonChars(words3);
  cout << "Common characters in [abc, bca, cab]: ";
  for (const string &s : result3)
  {
    cout << s << " ";
  }
  cout << endl;

  vector<string> words4 = {"abc", "def", "ghi"};
  vector<string> result4 = solution.commonChars(words4);
  cout << "Common characters in [abc, def, ghi]: ";
  for (const string &s : result4)
  {
    cout << s << " ";
  }
  cout << endl;

  return 0;
}
