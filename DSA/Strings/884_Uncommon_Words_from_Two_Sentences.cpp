#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

vector<string> uncommonFromSentences(string s1, string s2)
{
  map<string, int> mp; // Map to store the frequency of each word

  stringstream ss1(s1), ss2(s2); // Initialize stringstreams for both sentences
  string word;

  // Count occurrences of words in the first sentence
  while (ss1 >> word)
  {
    mp[word]++;
  }

  // Count occurrences of words in the second sentence
  while (ss2 >> word)
  {
    mp[word]++;
  }

  vector<string> ans;

  // Collect words that appear exactly once
  for (auto &x : mp)
  {
    if (x.second == 1)
    {
      ans.push_back(x.first);
    }
  }

  return ans;
}

int main()
{
  string s1 = "this apple is sweet";
  string s2 = "this apple is sour";

  vector<string> result = uncommonFromSentences(s1, s2);

  // Output the result
  for (const string &word : result)
  {
    cout << word << " ";
  }

  return 0;
}
