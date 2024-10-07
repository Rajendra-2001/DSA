#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to calculate the minimum length after removing pairs
int minLength(string s)
{
  stack<char> charStack;
  // Iterate through each character in the string
  for (char currentChar : s)
  {
    // If the stack is not empty and we find a matching pair, pop the stack
    if (!charStack.empty() &&
        ((charStack.top() == 'A' && currentChar == 'B') ||
         (charStack.top() == 'C' && currentChar == 'D')))
    {
      charStack.pop(); // Remove the matching pair
    }
    else
    {
      charStack.push(currentChar); // Otherwise, add the current character to the stack
    }
  }
  return charStack.size(); // The remaining size of the stack is the result
}

int main()
{
  // Example test cases
  string test1 = "ACBDCBAD";
  string test2 = "AABB";
  string test3 = "ABCD";
  string test4 = "AABCDDCBAA";

  // Call the minLength function with different test cases
  cout << "Test case 1: " << test1 << ", Remaining length: " << minLength(test1) << endl; // Expected output: 0
  cout << "Test case 2: " << test2 << ", Remaining length: " << minLength(test2) << endl; // Expected output: 2
  cout << "Test case 3: " << test3 << ", Remaining length: " << minLength(test3) << endl; // Expected output: 0
  cout << "Test case 4: " << test4 << ", Remaining length: " << minLength(test4) << endl; // Expected output: 4

  return 0;
}
