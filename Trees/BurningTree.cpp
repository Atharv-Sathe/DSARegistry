#include <bits/stdc++.h>
using namespace std;

/*
  Given a binary tree and a target node, determine the minimum time required to 
  burn the entire tree if the target node is set on fire. In one second, the fire 
  spreads from a node to its left child, right child, and parent.
  Note: The tree contains unique values.
*/

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

bool arson(Node* root, int target, int& burnTime, int& minBurnTime) {
  if (!root) return false;
  if (root->data == target) {
    minBurnTime = max(minBurnTime, subtreeBurnTime(root, burnTime));
    return true;
  }

  bool isLeft = false, isRight = false;
  isLeft = arson(root->left, target, burnTime, minBurnTime);
  if (!isLeft) isRight = arson(root->right, target, burnTime, minBurnTime);

  if (!isLeft && !isRight) return false;

  burnTime++;
  int subTreeBT = 0;
  if (isLeft && root->right) {
    subTreeBT = subtreeBurnTime(root->right, burnTime + 1);
  } else if (isRight && root->left) {
    subTreeBT = subtreeBurnTime(root->left, burnTime + 1);
  }
  // If SubTreeBT = 0, this means there was no available left
  // or right tree, meaning we will take burnTime
  minBurnTime = max(minBurnTime, max(subTreeBT, burnTime));

  return true;
}

int subtreeBurnTime(Node* root, int strtTime) {
  queue<Node*> q;
  q.push(root);
  int burnTime = strtTime;
  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++) {
      Node* node = q.front();
      q.pop();

      if (node->left) q.push(node->left);
      if (node->right) q.push(node->right);
    }
    burnTime++;
  }
  return burnTime - 1;
}

int main() { return 0; }