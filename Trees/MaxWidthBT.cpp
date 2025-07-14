#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the
leftmost and rightmost non-null nodes), where the null nodes between the
end-nodes that would be present in a complete binary tree extending down to that
level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

int widthOfBinaryTree(TreeNode* root) {
  queue<pair<TreeNode*, unsigned long long>> q;
  q.push({root, 0});

  int maxWidth = 1;
  while (!q.empty()) {
    int levelSize = q.size();
    unsigned long long leftMost = q.front().second;
    unsigned long long rightMost = leftMost;

    for (int i = 0; i < levelSize; i++) {
      auto [node, pos] = q.front();
      q.pop();

      rightMost = pos;

      if (node->left) {
        q.push({node->left, 2 * pos});
      }

      if (node->right) {
        q.push({node->right, 2 * pos + 1});
      }
    }

    maxWidth = max(maxWidth, (int)(rightMost - leftMost + 1));
  }
  return maxWidth;
}

int main() { return 0; }