#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree
in one traversal.
*/


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root){
  // Write your code here.
  vector<int> inorder;
  vector<int> preorder;
  vector<int> postorder;

  // 1 : preorder
  // 2 : inorder
  // 3 : postorder
  stack<pair<TreeNode*, int>> st;
  st.push({root, 1});
  
  while(!st.empty()) {
      auto [curr, state] = st.top();
      st.pop();

      if (state == 1) {
          preorder.push_back(curr -> data);
          st.push({curr, 2});
          if (curr -> left) st.push({curr -> left, 1});
      } else if (state == 2) {
          inorder.push_back(curr -> data);
          st.push({curr, 3});
          if (curr -> right) st.push({curr -> right, 1});
      } else {
          postorder.push_back(curr -> data);
      }
  }
  return {inorder, preorder, postorder};
}

int main() {
  
  return 0;
}