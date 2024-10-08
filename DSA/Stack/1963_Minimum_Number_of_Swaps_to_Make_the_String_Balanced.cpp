#include <iostream>
#include <stack>
using namespace std;

int minSwaps(string s)
{
  stack<char> st;

  for (char &ch : s)
  {
    if (ch == '[')
    {
      st.push(ch); // Push opening bracket
    }
    else if (!st.empty())
    {
      st.pop(); // Pop a matching opening bracket
    }
  }

  // The remaining unmatched brackets need to be swapped to balance
  return (st.size() + 1) / 2;
}

int main()
{
  // Test cases
  string test1 = "[]][][";
  string test2 = "[][]";
  string test3 = "]]][[[";
  string test4 = "[][][]";

  cout << "Test case 1: " << test1 << ", Minimum swaps: " << minSwaps(test1) << endl; // Expected output: 1
  cout << "Test case 2: " << test2 << ", Minimum swaps: " << minSwaps(test2) << endl; // Expected output: 0
  cout << "Test case 3: " << test3 << ", Minimum swaps: " << minSwaps(test3) << endl; // Expected output: 2
  cout << "Test case 4: " << test4 << ", Minimum swaps: " << minSwaps(test4) << endl; // Expected output: 0

  return 0;
}
