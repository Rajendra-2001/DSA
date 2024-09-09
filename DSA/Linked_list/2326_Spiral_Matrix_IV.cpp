#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
  // Step 1: Calculate the length of the linked list and fill it with -1 if needed
  int l = 1;
  ListNode *p = head;

  while (p->next != NULL)
  {
    l++;
    p = p->next;
  }

  // Add new nodes with value -1 until the length matches m * n
  while (l != m * n)
  {
    ListNode *q = new ListNode(-1); // Create a new node with value -1
    p->next = q;                    // Attach the new node to the list
    p = q;                          // Move to the new node
    l++;                            // Increment the length to match m * n
  }

  // Step 2: Initialize the result matrix with dimensions m x n
  vector<vector<int>> ans(m, vector<int>(n, 0)); // Initialize with 0

  // Step 3: Fill the matrix in spiral order
  int top = 0, bottom = m - 1, left = 0, right = n - 1;
  ListNode *curr = head;

  while (top <= bottom && left <= right)
  {
    // Traverse from left to right on the top row
    for (int i = left; i <= right; i++)
    {
      ans[top][i] = curr->val;
      curr = curr->next;
    }
    top++;

    // Traverse from top to bottom on the right column
    for (int i = top; i <= bottom; i++)
    {
      ans[i][right] = curr->val;
      curr = curr->next;
    }
    right--;

    // Traverse from right to left on the bottom row
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        ans[bottom][i] = curr->val;
        curr = curr->next;
      }
      bottom--;
    }

    // Traverse from bottom to top on the left column
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        ans[i][left] = curr->val;
        curr = curr->next;
      }
      left++;
    }
  }

  return ans;
}

int main()
{
  // Create a linked list: 1 -> 2 -> 3 -> 4
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  // Variables m and n
  int m = 1;
  int n = 4;

  // Call the spiralMatrix function
  vector<vector<int>> result = spiralMatrix(m, n, head);

  // Output the resulting spiral matrix
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
