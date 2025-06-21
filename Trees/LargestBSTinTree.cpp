#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

bool isBST(Node* root, int maxVal, int minVal) {
  if (!root) return true;

  if (root->data <= minVal || root->data >= maxVal) return false;

  return isBST(root->left, root->data, minVal) &&
         isBST(root->right, maxVal, root->data);
}

int getSize(Node* root) {
  if (!root) return 0;

  return 1 + getSize(root->left) + getSize(root->right);
}

void findLargest(Node* root, int& lgst) {
  if (!root) return;

  if (isBST(root, INT_MAX, INT_MIN)) {
    lgst = max(lgst, getSize(root));
  }

  findLargest(root->left, lgst);
  findLargest(root->right, lgst);
}

// Alternative cleaner approach with better variable names
struct BSTInfo {
  int minVal;
  int maxVal;
  int size;
  bool isBST;
};

BSTInfo largestBSTHelper(Node* root) {
  if (!root) {
    return {INT_MAX, INT_MIN, 0, true};
  }

  BSTInfo left = largestBSTHelper(root->left);
  BSTInfo right = largestBSTHelper(root->right);

  // Check if current subtree can form a BST
  if (left.isBST && right.isBST &&
      (root->left == nullptr || left.maxVal < root->data) &&
      (root->right == nullptr || right.minVal > root->data)) {
    // Current subtree is a valid BST
    return {(root->left) ? left.minVal : root->data,    // min of subtree
            (root->right) ? right.maxVal : root->data,  // max of subtree
            1 + left.size + right.size,                 // total size
            true};
  }

  // Not a valid BST, return max size found so far
  return {0, 0, max(left.size, right.size), false};
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node* root) {
  // int lgst = 0;
  // findLargest(root, lgst);
  // return lgst;

  return largestBSTHelper(root).size;
}

int main() { return 0; }