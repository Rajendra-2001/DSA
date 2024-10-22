#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to find the k-th largest level sum in the binary tree
long long kthLargestLevelSum(TreeNode* root, int k) {
    if (!root) return -1;  // If the tree is empty
    
    // Min-heap to store the k-largest sums
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    // Queue for BFS traversal
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        long long sum = 0;
        
        // Calculate the sum for the current level
        while (size > 0) {
            TreeNode* temp = q.front();
            q.pop();
            sum += temp->val;
            
            // Push the children of the current node into the queue
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            size--;
        }
        
        pq.push(sum);  // Add the level sum to the min-heap
        
        // If heap size exceeds k, remove the smallest element
        if (pq.size() > k) pq.pop();
    }
    
    // If there are fewer than k levels, return -1
    return pq.size() < k ? -1 : pq.top();
}

// Driver code to test the function
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int k = 2;
    cout << "The " << k << "-th largest level sum is: " << kthLargestLevelSum(root, k) << endl;

    return 0;
}
