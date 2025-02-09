#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int getMaxPathSum(Node* root, int& maxPSum) {
    if (!root) return 0;
    
    // No point of considering a branch if its sum is negative
    int leftMaxSum = max(0, getMaxPathSum(root -> left, maxPSum));
    int rightMaxSum = max(0, getMaxPathSum(root -> right, maxPSum));
    maxPSum = max(maxPSum, leftMaxSum + rightMaxSum + root -> data);
    
    return root -> data + max(leftMaxSum, rightMaxSum);
}

// Function to return maximum path sum from any node in a tree.
int findMaxSum(Node *root) {
    int maxPathSum = INT_MIN;
    getMaxPathSum(root, maxPathSum);
    return maxPathSum;
}

/*
Given a binary tree, the task is to find the maximum path sum. 
The path may start and end at any node in the tree.
*/

int main() {
    
    return 0;
}