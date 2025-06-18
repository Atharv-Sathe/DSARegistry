#include <iostream>
using namespace std;

/*
You are given root node of the BST and an integer key. You need to find the
in-order successor and predecessor of the given key. If either predecessor or
successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the
predecessor and the number just greater than the target is the successor.
*/

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    data = x;
    left = NULL;
    right = NULL;
  }
};

Node* successor(Node* root, int key) {
  // Store the last node in whose left subtree key is present
  Node* successor = nullptr;
  while (root) {
    if (key < root->data) {
      successor = root;
      root = root->left;
    } else {
      root = root->right;
    }
  }

  return successor;
}

Node* predecessor(Node* root, int key) {
  Node* predecessor = nullptr;
  while (root) {
    if (key > root->data) {
      predecessor = root;
      root = root->right;
    } else {
      root = root->left;
    }
  }

  return predecessor;
}

int main() { return 0; }