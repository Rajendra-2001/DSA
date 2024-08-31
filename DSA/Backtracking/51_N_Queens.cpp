#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
  int dumcol = col;
  int dumrow = row;

  // Check upper diagonal on left side
  while (row >= 0 && col >= 0)
  {
    if (board[row][col] == 'Q')
    { // Fix: '==' instead of "=="
      return false;
    }
    row--;
    col--;
  }

  col = dumcol;
  row = dumrow;

  // Check this column on upper side
  while (row >= 0)
  { // Fix: No need to check col >= 0 since col is fixed
    if (board[row][col] == 'Q')
    { // Fix: '==' instead of "=="
      return false;
    }
    row--;
  }

  col = dumcol;
  row = dumrow;

  // Check upper diagonal on right side
  while (row >= 0 && col < n)
  { // Fix: col should be less than n
    if (board[row][col] == 'Q')
    { // Fix: '==' instead of "=="
      return false;
    }
    row--;
    col++;
  }

  return true;
}

void solveNqueen(vector<vector<string>> &Solution, vector<string> &board, int row, int n)
{
  if (row == n)
  {
    Solution.push_back(board);
    return;
  }
  for (int col = 0; col < n; col++)
  {
    if (isSafe(board, row, col, n))
    {
      board[row][col] = 'Q'; // Fix: '=' instead of '=='
      solveNqueen(Solution, board, row + 1, n);
      board[row][col] = '.'; // Fix: '=' instead of '=='
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> Solution;
  vector<string> board(n, string(n, '.'));
  solveNqueen(Solution, board, 0, n);
  return Solution;
}

int main()
{
  int n = 10;
  vector<vector<string>> solutions = solveNQueens(n);

  for (const auto &solution : solutions)
  {
    for (const auto &row : solution)
    {
      cout << row << endl;
    }
    cout << endl;
  }

  return 0;
}
