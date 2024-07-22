#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> sortPeople(vector<string> &names, vector<int> &heights)
{
  int n = names.size();
  // Create a vector of pairs where each pair consists of a height and a corresponding name
  vector<pair<int, string>> hn(n);
  for (int i = 0; i < n; i++)
    hn[i] = {heights[i], names[i]};

  // Sort the vector of pairs in descending order based on height
  sort(hn.begin(), hn.end(), greater<>());

  // Extract the sorted names back into the names vector
  for (int i = 0; i < n; i++)
    names[i] = hn[i].second;

  return names;
}

// Driver code
int main()
{
  vector<string> names = {"Alice", "Bob", "Charlie"};
  vector<int> heights = {155, 180, 165};

  vector<string> sortedNames = sortPeople(names, heights);

  cout << "Sorted names by height in descending order:" << endl;
  for (const string &name : sortedNames)
  {
    cout << name << endl;
  }

  return 0;
}
