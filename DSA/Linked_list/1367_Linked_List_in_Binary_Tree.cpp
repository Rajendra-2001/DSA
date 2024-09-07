#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check if there is a subpath from the current tree node that matches the linked list.
bool solve(ListNode *head, TreeNode *root)
{
  if (head == NULL)
    return true; // If we reached the end of the linked list, we found a valid path
  if (root == NULL)
    return false; // If we reached a null node in the tree, it's not a valid path
  if (root->val != head->val)
    return false; // If values don't match, it's not a valid path

  // Recursively check if the path continues in either the left or right subtree
  return solve(head->next, root->left) || solve(head->next, root->right);
}

// Function to check if there exists a subpath in the binary tree that matches the linked list.
bool isSubPath(ListNode *head, TreeNode *root)
{
  if (root == NULL)
    return false; // Base case: no tree node means no path can be found

  // Check if the current root can be the start of the path, or check its left or right children as starting points
  return solve(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

// Helper function to create a linked list from an array.
ListNode *createLinkedList(int arr[], int n)
{
  if (n == 0)
    return nullptr;
  ListNode *head = new ListNode(arr[0]);
  ListNode *curr = head;
  for (int i = 1; i < n; i++)
  {
    curr->next = new ListNode(arr[i]);
    curr = curr->next;
  }
  return head;
}

// Helper function to create a binary tree (example function).
TreeNode *createTree()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(4);
  root->right = new TreeNode(4);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(1);
  root->right->left = new TreeNode(2);
  root->right->left->left = new TreeNode(6);
  root->right->left->right = new TreeNode(8);
  root->right->left->right->left = new TreeNode(1);
  root->right->left->right->right = new TreeNode(3);
  return root;
}

// Main function
int main()
{
  // Create a sample linked list: 4 -> 2 -> 8
  int listArr[] = {4, 2, 8};
  int n = sizeof(listArr) / sizeof(listArr[0]);
  ListNode *head = createLinkedList(listArr, n);

  // Create a sample binary tree
  TreeNode *root = createTree();

  // Check if the linked list is a subpath in the binary tree
  bool result = isSubPath(head, root);

  if (result)
  {
    cout << "The linked list is a subpath in the binary tree." << endl;
  }
  else
  {
    cout << "The linked list is NOT a subpath in the binary tree." << endl;
  }

  return 0;
}
