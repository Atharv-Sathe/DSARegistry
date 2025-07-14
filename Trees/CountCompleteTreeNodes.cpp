#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
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

bool nodeExists(TreeNode* root, int height, int pos) {
  TreeNode* curr = root;

  for (int i = height - 1; i >= 0; i--) {
    if ((pos >> i) & 1)
      curr = curr->right;
    else
      curr = curr->left;
  }

  if (!curr) return false;
  return true;
}

int countNodes(TreeNode* root) {
  // TC : O(n)
  // if (!root) return 0;
  // queue<TreeNode*> q;
  // q.push(root);

  // int level = 0;
  // int levelSize;
  // while(!q.empty()) {
  //     levelSize = q.size();

  //     for (int i = 0; i < levelSize; i++) {
  //         TreeNode* node = q.front();
  //         q.pop();

  //         if (node -> left) q.push(node -> left);
  //         if (node -> right) q.push(node -> right);
  //     }

  //     if (!q.empty()) {
  //         level++;
  //     }
  // }

  // return ((1 << level) - 1) + levelSize;

  // TC : O(log^2 N)
  if (!root) return 0;
  int height = 0;
  TreeNode* curr = root;
  while (curr->left) {
    height++;
    curr = curr->left;
  }

  int low = 0, high = (1 << height) - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nodeExists(root, height, mid))
      low = mid + 1;
    else
      high = mid - 1;
  }
  return ((1 << height) - 1) + low;
}

int main() { return 0; }