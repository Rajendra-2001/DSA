#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{

  int n = s2.size();
  vector<int> curr(26, 0), freq(26, 0);
  for (auto &it : s1)
    curr[it - 'a']++;
  int i = 0, j = 0;
  while (j < n)
  {
    freq[s2[j] - 'a']++;
    if (j - i + 1 == s1.size())
    {
      if (freq == curr)
        return true;
      freq[s2[i] - 'a']--;
      i++;
    }
    j++;
  }
  return false;
}

int main()
{
  string s1 = "ab";
  string s2 = "abcfjemkf";
  bool k = checkInclusion(s1, s2);
  cout << k;
}