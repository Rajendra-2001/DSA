#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int val;
  vector<Node *> children;
};

void postorderHelper(Node *root, vector<int> &ans)
{
  if (!root)
  {
    return;
  }

  // Recursively visit all children
  for (auto n : root->children)
  {
    postorderHelper(n, ans);
  }

  // Process the current node after its children
  ans.push_back(root->val);
}

vector<int> postorder(Node *root)
{
  vector<int> ans;
  postorderHelper(root, ans);
  return ans;
}

int main()
{
  // Create the N-ary tree nodes
  Node *root = new Node{1};
  Node *child1 = new Node{3};
  Node *child2 = new Node{2};
  Node *child3 = new Node{4};
  Node *grandchild1 = new Node{5};
  Node *grandchild2 = new Node{6};

  // Build the tree
  child1->children.push_back(grandchild1);
  child1->children.push_back(grandchild2);
  root->children.push_back(child1);
  root->children.push_back(child2);
  root->children.push_back(child3);

  // Get the postorder traversal
  vector<int> result = postorder(root);

  // Print the result
  for (int val : result)
  {
    cout << val << " ";
  }

  return 0;
}
