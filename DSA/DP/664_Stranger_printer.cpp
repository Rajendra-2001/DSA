#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

// Recursive function to calculate the minimum number of turns
// needed to print the substring s[i...j]
int f(int i, int j, string &s, vector<vector<int>> &dp)
{
  // Base case: if the substring is a single character, it only takes 1 turn to print
  if (i == j)
    return 1;

  // If the result for this substring has already been computed, return it
  if (dp[i][j] != -1)
    return dp[i][j];

  int ans = INT_MAX;

  // Iterate over all possible partitions of the substring s[i...j]
  for (int x = i; x < j; x++)
  {
    // Compute the minimum turns needed by splitting the substring into s[i...x] and s[x+1...j]
    ans = min(ans, f(i, x, s, dp) + f(x + 1, j, s, dp));
  }

  // If the first and last characters are the same, reduce the total number of turns by 1
  return dp[i][j] = (s[i] == s[j]) ? ans - 1 : ans;
}

// Function to initiate the calculation
int strangePrinter(string s)
{
  int n = s.length();

  // Initialize the memoization table with -1, indicating that no subproblem has been solved yet
  vector<vector<int>> dp(n, vector<int>(n, -1));

  // Start the recursion from the full string
  return f(0, n - 1, s, dp);
}

// Driver code
int main()
{
  string s = "aaabbb"; // Example input
  int result = strangePrinter(s);
  cout << "Minimum number of turns to print the string \"" << s << "\": " << result << endl;
  return 0;
}
