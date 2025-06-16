#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers preorder, which represents the preorder traversal of
a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with
the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of
Node.left has a value strictly less than Node.val, and any descendant of
Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then
traverses Node.left, then traverses Node.right.
*/

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

void insert(TreeNode* root, TreeNode* val) {
  if (root->val > val->val) {
    if (root->left)
      insert(root->left, val);
    else
      root->left = val;
  } else {
    if (root->right)
      insert(root->right, val);
    else
      root->right = val;
  }

  return;
}

TreeNode* onePassBuild(vector<int>& preorder, int& ind, int max, int min) {
  if (ind == preorder.size()) return nullptr;

  if (preorder[ind] > max || preorder[ind] < min) return nullptr;

  TreeNode* newNode = new TreeNode(preorder[ind]);
  ind++;

  TreeNode* left = onePassBuild(preorder, ind, newNode->val, min);
  TreeNode* right = onePassBuild(preorder, ind, max, newNode->val);

  newNode->left = left;
  newNode->right = right;

  return newNode;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
  TreeNode* root = new TreeNode(preorder[0]);

  // for (int i = 1; i < preorder.size(); i++) {
  //     TreeNode* newNode = new TreeNode(preorder[i]);
  //     insert(root, newNode);
  // }

  // return root;
  int ind = 0;
  return onePassBuild(preorder, ind, INT_MAX, INT_MIN);
}

int main() { return 0; }