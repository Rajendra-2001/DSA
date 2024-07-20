#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
{
  int numRows = rowSum.size();
  int numCols = colSum.size();
  vector<vector<int>> result(numRows, vector<int>(numCols, 0));

  int i = 0, j = 0;

  // Iterate through rows and columns
  while (i < numRows && j < numCols)
  {
    // Get the minimum of the current row and column sum
    int val = min(rowSum[i], colSum[j]);
    // Assign this value to the result matrix
    result[i][j] = val;
    // Subtract this value from the row and column sums
    rowSum[i] -= val;
    colSum[j] -= val;

    // Move to the next row if the current row sum is zero
    if (rowSum[i] == 0)
    {
      i++;
    }
    // Move to the next column if the current column sum is zero
    if (colSum[j] == 0)
    {
      j++;
    }
  }
  return result;
}

// Driver code
int main()
{
  vector<int> rowSum = {3, 8, 7};
  vector<int> colSum = {5, 7, 6};

  vector<vector<int>> result = restoreMatrix(rowSum, colSum);

  cout << "Restored Matrix:" << endl;
  for (const auto &row : result)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
