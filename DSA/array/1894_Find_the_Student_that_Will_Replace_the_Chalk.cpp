#include <iostream>
#include <vector>
#include <numeric> // For accumulate function

using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
  int n = chalk.size();
  long long sum = accumulate(chalk.begin(), chalk.end(), 0LL); // Use 0LL to ensure sum is long long
  int t = k % sum;                                             // Reduce k using modulo sum to get the remaining chalk

  for (int i = 0; i < n; ++i)
  {
    if (t < chalk[i])
    {
      return i;
    }
    t -= chalk[i]; // Subtract the current student's chalk usage from t
  }

  // Fallback return, though logically unreachable
  return -1;
}

int main()
{
  // Test case 1
  vector<int> chalk1 = {5, 1, 5};
  int k1 = 22;
  cout << "The student who will replace the chalk in test case 1 is: " << chalkReplacer(chalk1, k1) << endl;

  // Test case 2
  vector<int> chalk2 = {3, 4, 1, 2};
  int k2 = 25;
  cout << "The student who will replace the chalk in test case 2 is: " << chalkReplacer(chalk2, k2) << endl;

  // Test case 3
  vector<int> chalk3 = {2, 2, 2, 2};
  int k3 = 8;
  cout << "The student who will replace the chalk in test case 3 is: " << chalkReplacer(chalk3, k3) << endl;

  return 0;
}
