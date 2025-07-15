#include <bits/stdc++.h>
using namespace std;

/*
Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, or transmitted 
across a network connection link to be reconstructed later in the same or another 
computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no 
restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes 
a binary tree. You do not necessarily need to follow this format, so please be 
creative and come up with different approaches yourself.
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

TreeNode* buildTree(queue<string>& tokens) {
  string val = tokens.front();
  tokens.pop();

  if (val == "null") return nullptr;
  TreeNode* node = new TreeNode(stoi(val));
  node->left = buildTree(tokens);
  node->right = buildTree(tokens);
  return node;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
  if (!root) return "null,";
  return to_string(root->val) + ',' + serialize(root->left) +
         serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
  queue<string> tokens;
  istringstream ss(data);
  string token;
  while (getline(ss, token, ',')) {
    tokens.push(token);
  }
  return buildTree(tokens);
}

int main() { return 0; }