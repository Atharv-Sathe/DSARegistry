#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays preorder and inorder where preorder is the preorder 
traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.
*/

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* buildTreeRecurse(vector<int>& preorder, int pS, int pE,
                           vector<int>& inorder, int iS, int iE,
                           unordered_map<int, int>& inorderMap) {
  // If the left or right subtrees are empty then we return nullptr
  if (pS > pE || iS > iE) return nullptr;

  // Get Root
  int rootVal = preorder[pS];
  TreeNode* root = new TreeNode(rootVal);
  int rootInd = inorderMap[rootVal];

  // Partitioning inOrder
  int iLeftStart = iS;
  int iLeftEnd = rootInd - 1;
  int iRightStart = rootInd + 1;
  int iRightEnd = iE;

  // Partitioning preOrder
  int pLeftStart = pS + 1;
  int pLeftEnd = pLeftStart + (iLeftEnd - iLeftStart);
  int pRightStart = pLeftEnd + 1;
  int pRightEnd = pE;

  root->left = buildTreeRecurse(preorder, pLeftStart, pLeftEnd, inorder,
                                iLeftStart, iLeftEnd, inorderMap);
  root->right = buildTreeRecurse(preorder, pRightStart, pRightEnd, inorder,
                                 iRightStart, iRightEnd, inorderMap);

  return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  unordered_map<int, int> inorderMap;
  for (int i = 0; i < inorder.size(); i++) {
    inorderMap[inorder[i]] = i;
  }

  return buildTreeRecurse(preorder, 0, preorder.size() - 1, inorder, 0,
                          inorder.size() - 1, inorderMap);
}

int main() { return 0; }