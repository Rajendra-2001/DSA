#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dividePlayers(vector<int> &skill)
{
  int n = skill.size();
  if (n % 2 != 0)
    return -1; // If n is odd, we can't divide into teams of size 2

  // Step 1: Sort the skill array
  sort(skill.begin(), skill.end());

  // Step 2: Calculate the target sum (sum of smallest and largest skill)
  int target_sum = skill[0] + skill[n - 1];

  long long total_chemistry = 0;

  // Step 3: Form pairs from the sorted array
  for (int i = 0; i < n / 2; i++)
  {
    int pair_sum = skill[i] + skill[n - 1 - i];

    // Check if the pair sum matches the target sum
    if (pair_sum != target_sum)
    {
      return -1; // No valid division is possible
    }

    // Calculate the chemistry for this pair and add it to the total
    total_chemistry += (long long)skill[i] * skill[n - 1 - i];
  }

  return total_chemistry;
}

int main()
{
  vector<int> skill = {3, 2, 5, 1, 3, 4}; // Example input
  cout << dividePlayers(skill) << endl;   // Output will be the sum of team chemistry or -1 if no valid teams
  return 0;
}
