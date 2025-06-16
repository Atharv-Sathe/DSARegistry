#include <iostream>
using namespace std;

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of
two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is
defined between two nodes p and q as the lowest node in T that has both p and q
as descendants (where we allow a node to be a descendant of itself).”
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root) return nullptr;

  if (root == p || root == q) {
    return root;
  }

  if ((root->val > p->val && root->val < q->val) ||
      (root->val < p->val && root->val > q->val)) {
    return root;
  }

  if (root->val > p->val && root->val > q->val) return helper(root->left, p, q);

  return helper(root->right, p, q);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  return helper(root, p, q);
}

int main() { return 0; }