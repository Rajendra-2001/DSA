#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Function to rearrange the string as per the given conditions
string rearrangeString(int a, int b, int c)
{
  priority_queue<pair<int, char>> p;

  string ans = "";

  if (a > 0)
    p.push({a, 'a'});
  if (b > 0)
    p.push({b, 'b'});
  if (c > 0)
    p.push({c, 'c'});

  while (!p.empty())
  {
    if (p.top().first == 0)
      break;

    int x = p.top().first;
    char y = p.top().second;
    p.pop();

    if (ans.size() >= 2 && ans[ans.size() - 1] == ans[ans.size() - 2] && ans[ans.size() - 1] == y)
    {
      if (p.empty())
        break;
      int occ = p.top().first;
      char val = p.top().second;
      p.pop();

      if (occ == 0)
        break;

      ans += val;
      occ--;

      p.push({occ, val});
    }
    else
    {
      ans += y;
      x--;
    }

    if (x > 0)
      p.push({x, y});
  }

  return ans;
}

int main()
{
  // Example input for a, b, and c
  int a = 6, b = 1, c = 1; // Example: 6 'a's, 1 'b', and 1 'c'

  // Call the function to rearrange the string
  string result = rearrangeString(a, b, c);

  // Output the result
  cout << "The rearranged string is: " << result << endl;

  return 0;
}
