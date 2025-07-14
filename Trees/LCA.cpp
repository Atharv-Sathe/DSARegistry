#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

TreeNode* getLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return nullptr;

  // Find p or q in left subtree
  TreeNode* left = getLCA(root->left, p, q);
  TreeNode* right = getLCA(root->right, p, q);

  if ((left == p && right == q) || (left == q && right == p) ||
      (root == p || root == q) ||
      ((left || right) && (root == p || root == q))) {
    return root;
  }

  return (left ? left : (right) ? right : nullptr);
}

int main() { return 0; }