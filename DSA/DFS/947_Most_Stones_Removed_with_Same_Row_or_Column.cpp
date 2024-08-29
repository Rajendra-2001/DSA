#include <vector>
#include <bits/stdc++.h>
using namespace std;

// DFS function to explore all stones that can be removed
int dfs(vector<vector<int>> &stones, int idx, int m, vector<bool> &visited)
{
  visited[idx] = true;
  int result = 0;

  for (int i = 0; i < m; i++)
  {
    // Check if the stone is not visited and is in the same row or column
    if (!visited[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1]))
    {
      result += (dfs(stones, i, m, visited) + 1);
    }
  }

  return result;
}

// Function to find the maximum number of stones that can be removed
int removeStones(vector<vector<int>> &stones)
{
  int m = stones.size();
  int ans = 0;
  vector<bool> visited(m, false); // Initialize visited vector with false

  for (int i = 0; i < m; i++)
  {
    // If the stone has not been visited, start a DFS
    if (!visited[i])
    {
      ans += dfs(stones, i, m, visited);
    }
  }

  return ans;
}

int main()
{
  // Example input: stones positioned on a grid
  vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};

  // Call the removeStones function
  int result = removeStones(stones);

  // Output the result
  cout << "Maximum number of stones that can be removed: " << result << endl;

  return 0;
}
