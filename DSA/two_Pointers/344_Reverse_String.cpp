#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

void reverseString(vector<char> &s)
{
  int n = s.size();
  int st = 0, end = n - 1;
  while (st < end)
  {
    // Swap the elements directly
    swap(s[st], s[end]);
    st++;
    end--;
  }
}

int main()
{
  // Test case
  vector<char> s = {'h', 'e', 'l', 'l', 'o'};

  cout << "Original string: ";
  for (char c : s)
  {
    cout << c;
  }
  cout << endl;

  // Reverse the string
  reverseString(s);

  // Print the reversed string
  cout << "Reversed string: ";
  for (char c : s)
  {
    cout << c;
  }
  cout << endl;

  return 0;
}
