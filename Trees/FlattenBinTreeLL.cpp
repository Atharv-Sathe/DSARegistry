#include <bits/stdc++.h>
using namespace std;

/*
 Given the root of a binary tree, flatten the tree into a "linked list":

 The "linked list" should use the same TreeNode class where the right 
 child pointer points to the next node in the list and the left child pointer 
 is always null.
 The "linked list" should be in the same order as a pre-order traversal of the 
 binary tree.
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

void flatten(TreeNode *root) {
  TreeNode *curr = root;
  while (curr) {
    while (curr->left) {
      TreeNode *temp = curr->left;
      while (temp->right) {
        temp = temp->right;
      }
      temp->right = curr->right;
      curr->right = curr->left;
      curr->left = nullptr;
    }
    curr = curr->right;
  }
}

int main() { return 0; }