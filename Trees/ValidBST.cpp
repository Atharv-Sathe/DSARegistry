#include <iostream>
using namespace std;

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

bool isBST(TreeNode *root, long minVal, long maxVal) {
  if (!root) return true;

  if (root->val >= maxVal || root->val <= minVal) return false;

  return isBST(root->left, minVal, root->val) &&
         isBST(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root) {
  return isBST(root->left, LONG_MIN, root->val) &&
         isBST(root->right, root->val, LONG_MAX);
}
int main() { return 0; }