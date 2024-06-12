#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int padovanSequence(int n)
  {
    // Base cases
    if (n == 0 || n == 1 || n == 2)
      return 1;

    // Initializing the first three terms of the Padovan sequence
    int a0 = 1, a1 = 1, a2 = 1;
    int temp = 1;

    // Iteratively compute the Padovan sequence up to the n-th term
    for (int i = 3; i <= n; i++)
    {
      // Calculate the next term as the sum of the (i-2)th and (i-3)th terms
      temp = (a0 + a1) % 1000000007;

      // Update the previous terms for the next iteration
      a0 = a1;
      a1 = a2;
      a2 = temp;
    }

    // Return the n-th term of the Padovan sequence
    return a2;
  }
};
void printResult(int n, int result)
{
  cout << "Padovan(" << n << ") = " << result << endl;
}

int main()
{
  Solution solution;

  // Test cases
  vector<int> testCases = {0, 1, 2, 3, 4, 5, 6, 10, 20, 30, 50, 100, 1000};

  for (int n : testCases)
  {
    int result = solution.padovanSequence(n);
    printResult(n, result);
  }

  return 0;
}