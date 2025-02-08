#include <iostream>
#include <vector>

using namespace std;

/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the 
following order: 

Left Boundary: This includes all the nodes on the path from the root to the 
leftmost leaf node. You must prefer the left child over the right child when traversing. 
Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or 
right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost 
leaf node to the root, traversed in reverse order. You must prefer the right child 
over the left child when traversing. Do not include the root in this section if it 
was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root 
itself is the left or right boundary. 
*/

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* node) {
    return !node->left && !node->right;
}

void addLeftBoundry(Node* root, vector<int>& res) {
    if (!root || isLeaf(root)) return;
    
    res.push_back(root -> data);
    if (root -> left) addLeftBoundry(root -> left, res);
    else if (root -> right) addLeftBoundry(root -> right, res);
}

void addLeafNodes(Node* root, vector<int>& res) {
    if (!root) return ;
    if (isLeaf(root)) {
        res.push_back(root -> data);
        return;
    }
    
    addLeafNodes(root -> left, res);
    addLeafNodes(root -> right, res);
}

void addRightBoundry(Node* root, vector<int>& res) {
    if (!root || isLeaf(root)) return;
    
    if (root -> right) addRightBoundry(root -> right, res);
    else if (root -> left) addRightBoundry(root -> left, res);
    res.push_back(root -> data);
}

vector<int> boundaryTraversal(Node *root) {
    if (isLeaf(root)) return {root -> data};
    vector<int> res;
    res.push_back(root -> data);
    
    addLeftBoundry(root -> left, res);
    addLeafNodes(root, res);
    addRightBoundry(root -> right, res);
    return res;
}


int main() {
    
    return 0;
}