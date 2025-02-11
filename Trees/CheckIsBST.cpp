#include <iostream>
using namespace std;

/*
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

bool inOrder(Node* root, int& prev) {
    if (!root) return true;
    
    if (!inOrder(root -> left, prev)) return false;
    
    if (prev >= root -> data) return false;
    prev = root -> data;
    
    if (!inOrder(root -> right, prev)) return false;
    
    return true;
} 

// Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) {
    // Your code here
    int prev = INT_MIN;
    return inOrder(root, prev);
}

int main() {
    
    return 0;
}