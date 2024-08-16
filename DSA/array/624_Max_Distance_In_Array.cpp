#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>> &arrays)
{
  int n = arrays.size();
  int min_num = arrays[0].front();
  int max_num = arrays[0].back();
  int max_dis = INT_MIN;

  for (int i = 1; i < n; i++)
  {
    max_dis = max({max_dis, abs(arrays[i].back() - min_num), abs(arrays[i].front() - max_num)});
    min_num = min(min_num, arrays[i].front());
    max_num = max(max_num, arrays[i].back());
  }

  return max_dis;
}

int main()
{
  vector<vector<int>> arrays1 = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
  vector<vector<int>> arrays2 = {{-1, 0, 3}, {7, 8}, {2, 4}};
  vector<vector<int>> arrays3 = {{1, 5}, {3, 4}, {6, 10}};
  vector<vector<int>> arrays4 = {{1, 4}, {2, 6}, {3, 5}};

  // Test case 1
  cout << "Test case 1: Maximum distance = " << maxDistance(arrays1) << endl;

  // Test case 2
  cout << "Test case 2: Maximum distance = " << maxDistance(arrays2) << endl;

  // Test case 3
  cout << "Test case 3: Maximum distance = " << maxDistance(arrays3) << endl;

  // Test case 4
  cout << "Test case 4: Maximum distance = " << maxDistance(arrays4) << endl;

  return 0;
}
