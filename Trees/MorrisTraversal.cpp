#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Morris Traversal TC : O(n) SC : O(1)
vector<int> morrisTraversal(TreeNode *root) {
  TreeNode *curr = root;
  vector<int> inorder;
  while (curr) {
    if (curr->left == nullptr) {
      inorder.push_back(curr->val);
      curr = curr->right;
    } else {
      TreeNode *temp = curr->left;
      while (temp->right && temp->right != curr) {
        temp = temp->right;
      }

      if (temp->right == nullptr) {
        // Create a thread to curr
        temp->right = curr;
        curr = curr->left;
      } else {
        // Remove the already existing thread and move right
        temp->right = nullptr;
        inorder.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return inorder;
}

int main() { return 0; }