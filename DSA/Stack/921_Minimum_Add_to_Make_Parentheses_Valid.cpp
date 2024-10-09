#include <iostream>
using namespace std;
int minAddToMakeValid(string s)
{
  int size = 0;   // Unmatched opening parentheses
  int closed = 0; // Unmatched closing parentheses

  for (char &ch : s)
  {
    if (ch == '(')
    {
      size++; // Increment unmatched opening parentheses
    }
    else if (ch == ')' && size > 0)
    {
      size--; // Match with an opening parenthesis
    }
    else if (ch == ')')
    {
      closed++; // Unmatched closing parenthesis
    }
  }

  // Total additions required to balance the parentheses
  return closed + size;
}

int main()
{
  // Test cases
  string test1 = "())";
  string test2 = "(((";
  string test3 = "()";
  string test4 = "(()())";
  string test5 = "((())";

  cout << "Test case 1: " << test1 << ", Minimum additions: " << minAddToMakeValid(test1) << endl; // Expected output: 1
  cout << "Test case 2: " << test2 << ", Minimum additions: " << minAddToMakeValid(test2) << endl; // Expected output: 3
  cout << "Test case 3: " << test3 << ", Minimum additions: " << minAddToMakeValid(test3) << endl; // Expected output: 0
  cout << "Test case 4: " << test4 << ", Minimum additions: " << minAddToMakeValid(test4) << endl; // Expected output: 0
  cout << "Test case 5: " << test5 << ", Minimum additions: " << minAddToMakeValid(test5) << endl; // Expected output: 1

  return 0;
}
