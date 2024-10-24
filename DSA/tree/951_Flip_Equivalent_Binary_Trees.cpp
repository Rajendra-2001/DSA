#include <iostream>
using namespace std;

// Define the structure for TreeNode
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are flip equivalent
bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
  if (root1 == NULL && root2 == NULL)
  {
    return true;
  }

  if (root1 == NULL || root2 == NULL || root1->val != root2->val)
  {
    return false;
  }

  bool withoutFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
  bool withFlip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

  return withFlip || withoutFlip;
}

// Driver function to test flipEquiv
int main()
{
  // Construct two trees for testing
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(3);
  root2->right = new TreeNode(2);
  root2->right->left = new TreeNode(4);
  root2->right->right = new TreeNode(5);

  bool result = flipEquiv(root1, root2);
  cout << "The trees are flip equivalent: " << (result ? "true" : "false") << endl;

  return 0;
}
