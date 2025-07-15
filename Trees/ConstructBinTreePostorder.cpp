#include <bits/stdc++.h>
using namespace std;

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the 
postorder traversal of the same tree, construct and return the binary tree.
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

TreeNode* buildTreeRecurse(vector<int>& postorder, int pS, int pE,
                           vector<int>& inorder, int iS, int iE,
                           unordered_map<int, int>& inorderMap) {
  if (pS > pE || iS > iE) return nullptr;

  // get root
  int rootVal = postorder[pE];
  TreeNode* root = new TreeNode(rootVal);
  int rootInd = inorderMap[rootVal];

  // Partition Inorder
  int iLeftStart = iS;
  int iLeftEnd = rootInd - 1;
  int iRightStart = rootInd + 1;
  int iRightEnd = iE;

  // Partition Postorder
  int pRightEnd = pE - 1;
  int pRightStart = pRightEnd - (iRightEnd - iRightStart);
  int pLeftStart = pS;
  int pLeftEnd = pRightStart - 1;

  root->left = buildTreeRecurse(postorder, pLeftStart, pLeftEnd, inorder,
                                iLeftStart, iLeftEnd, inorderMap);
  root->right = buildTreeRecurse(postorder, pRightStart, pRightEnd, inorder,
                                 iRightStart, iRightEnd, inorderMap);

  return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  unordered_map<int, int> inorderMap;
  for (int i = 0; i < inorder.size(); i++) {
    inorderMap[inorder[i]] = i;
  }

  return buildTreeRecurse(postorder, 0, postorder.size() - 1, inorder, 0,
                          inorder.size() - 1, inorderMap);
}

int main() { return 0; }