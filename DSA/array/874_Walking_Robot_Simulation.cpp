#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
  // Direction vectors: north, east, south, west
  vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int dir = 0;      // Start facing north
  int x = 0, y = 0; // Start at the origin
  int maxDistSq = 0;

  // Store obstacles in a set for quick lookup
  unordered_set<string> obstacleSet;
  for (const auto &obs : obstacles)
  {
    obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
  }

  for (const int &command : commands)
  {
    if (command == -2)
    {
      // Turn left 90 degrees
      dir = (dir + 3) % 4;
    }
    else if (command == -1)
    {
      // Turn right 90 degrees
      dir = (dir + 1) % 4;
    }
    else
    {
      // Move forward k units
      for (int i = 0; i < command; ++i)
      {
        int nextX = x + directions[dir].first;
        int nextY = y + directions[dir].second;
        string nextPos = to_string(nextX) + "," + to_string(nextY);

        if (obstacleSet.find(nextPos) == obstacleSet.end())
        {
          // Move to the next position if there's no obstacle
          x = nextX;
          y = nextY;
          maxDistSq = max(maxDistSq, x * x + y * y);
        }
        else
        {
          // Stop if an obstacle is encountered
          break;
        }
      }
    }
  }

  return maxDistSq;
}

int main()
{
  vector<int> commands = {4, -1, 3, -2, 4, 2, -1, 3};
  vector<vector<int>> obstacles = {{2, 4}, {3, 2}, {4, 3}};
  cout << robotSim(commands, obstacles) << endl; // Output the maximum distance squared
  return 0;
}
