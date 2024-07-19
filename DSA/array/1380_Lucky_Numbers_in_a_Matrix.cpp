#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
  int N = matrix.size();
  int M = matrix[0].size();

  vector<int> rowMin(N, INT_MAX);
  vector<int> colMax(M, INT_MIN);

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      rowMin[i] = min(rowMin[i], matrix[i][j]);
      colMax[j] = max(colMax[j], matrix[i][j]);
    }
  }

  vector<int> luckyNumbers;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
      {
        luckyNumbers.push_back(matrix[i][j]);
      }
    }
  }

  return luckyNumbers;
}
