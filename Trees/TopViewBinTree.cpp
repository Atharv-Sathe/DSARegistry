#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

/*
You are given a binary tree, and your task is to return its top view.
The top view of a binary tree is the set of nodes visible when the tree is
viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside
the shadow of the tree, consider the leftmost node only.
*/

struct Node {
  int data;
  Node *left;
  Node *right;
};

vector<int> topView(Node *root) {
  // code here
  vector<int> result;

  if (!root) return {};

  map<int, int> mp;

  queue<pair<Node *, int>> q;
  q.push({root, 0});

  while (!q.empty()) {
    // auto [node, horiD] = q.front();
    auto node = q.front().first;
    auto horiD = q.front().second;
    q.pop();

    if (mp.count(horiD) == 0) mp[horiD] = node->data;

    if (node->left) q.push({node->left, horiD - 1});
    if (node->right) q.push({node->right, horiD + 1});
  }

  for (const auto &p : mp) result.push_back(p.second);
  return result;
}

int main() { return 0; }