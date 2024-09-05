#include <iostream>
#include <vector>
#include <numeric>   // For accumulate
#include <algorithm> // For min

std::vector<int> missingRolls(std::vector<int> &rolls, int mean, int n)
{
  int m = rolls.size();

  // Calculate the sum of the m observed rolls
  int sum_m = std::accumulate(rolls.begin(), rolls.end(), 0);

  // Calculate the total sum that the n + m rolls should have
  int total_sum = (n + m) * mean;

  // Calculate the required sum for the missing n rolls
  int sum_n = total_sum - sum_m;

  // If sum_n is out of the possible range for n dice rolls, return an empty vector
  if (sum_n < n || sum_n > n * 6)
  {
    return {}; // Impossible to distribute
  }

  // Initialize the result vector with all 1s
  std::vector<int> result(n, 1);

  // Distribute the remaining sum across the elements
  int remaining = sum_n - n; // Remaining sum to distribute (since we already added 1 to each)

  for (int i = 0; i < n && remaining > 0; ++i)
  {
    int add = std::min(remaining, 6 - result[i]); // Add up to 6 without exceeding
    result[i] += add;
    remaining -= add;
  }

  return result;
}

int main()
{
  std::vector<int> rolls = {3, 4, 2, 5};
  int mean = 4;
  int n = 2;

  std::vector<int> missing = missingRolls(rolls, mean, n);

  // Output the result
  if (!missing.empty())
  {
    for (int roll : missing)
    {
      std::cout << roll << " ";
    }
  }
  else
  {
    std::cout << "No valid solution";
  }

  return 0;
}
