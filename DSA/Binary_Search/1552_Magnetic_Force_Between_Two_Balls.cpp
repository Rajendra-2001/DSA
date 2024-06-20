#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
  // Function to check if it is possible to place 'm' balls with at least 'force' distance apart
  bool possibleToPlace(int force, const std::vector<int> &pos, int m)
  {
    int pre = pos[0]; // Position of the first placed ball
    int cntBalls = 1; // Start with placing the first ball

    // Iterate over the positions starting from the second element
    for (int i = 1; i < pos.size(); i++)
    {
      int curr = pos[i];
      // If the current position is at least 'force' distance from the last placed ball
      if (curr - pre >= force)
      {
        cntBalls++; // Place the ball
        pre = curr; // Update the position of the last placed ball
      }
      // If we have placed all 'm' balls, we can break early
      if (cntBalls == m)
        break;
    }
    // Return true if we successfully placed all 'm' balls
    return cntBalls == m;
  }

  // Function to find the maximum minimum distance between any two of the placed balls
  int maxDistance(std::vector<int> &pos, int m)
  {
    int n = pos.size();
    // Sort the positions to make the placement easier
    std::sort(pos.begin(), pos.end());
    int minF = 1;                   // Minimum possible distance
    int maxF = pos[n - 1] - pos[0]; // Maximum possible distance (between the first and last positions)
    int ans = 0;

    // Binary search for the optimal distance
    while (minF <= maxF)
    {
      int midF = minF + (maxF - minF) / 2;
      // If it is possible to place the balls with at least 'midF' distance
      if (possibleToPlace(midF, pos, m))
      {
        ans = midF;      // Update the answer
        minF = midF + 1; // Try for a larger minimum distance
      }
      else
      {
        maxF = midF - 1; // Try for a smaller minimum distance
      }
    }
    return ans;
  }
};

// Driver code
int main()
{
  Solution solution;
  std::vector<int> positions = {1, 2, 3, 4, 7};
  int m = 3;

  int result = solution.maxDistance(positions, m);
  std::cout << "The maximum minimum distance is: " << result << std::endl;

  return 0;
}
