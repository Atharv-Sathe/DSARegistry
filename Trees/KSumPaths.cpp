#include <iostream>
#include <unordered_map>
using namespace std;

/*
Given a binary tree and an integer k, determine the number of 
downward-only paths where the sum of the node values in the path 
equals k. A path can start and end at any node within the tree but 
must always move downward (from parent to child).
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void traverseDown(Node* root, int k, int currSum, int& count) {
    if (!root) return;
    
    currSum += root -> data;
    if (currSum == k) count++;
    traverseDown(root -> left, k, currSum, count);
    traverseDown(root -> right, k, currSum, count);
    
}

void traverse(Node* root, int k, int& count) {
    if (!root) return;
    
    traverseDown(root, k, 0, count);
    traverse(root -> left, k, count);
    traverse(root -> right, k, count);
}

// Effecient Approach
void getCountKSum(Node* root, int k, unordered_map<int, int>& map, int currSum, int& count) {
    if (!root) return;
    
    currSum += root -> data;
    if (currSum == k) count++;
    
    if (map.count(currSum - k)) count += map[currSum - k];
    
    map[currSum]++;
    getCountKSum(root -> left, k, map, currSum, count);
    getCountKSum(root -> right, k, map, currSum, count);
    
    map[currSum]--;
    if (!map[currSum]) map.erase(currSum);
    return;
}

int sumK(Node *root, int k) {
        
    int count = 0;
    // Naive Approach 
    // traverse(root, k, count);
    
    // Better Approach
    unordered_map<int, int> map;
    getCountKSum(root, k, map, 0, count);
    return count;
}

int main() {
    
    return 0;
}