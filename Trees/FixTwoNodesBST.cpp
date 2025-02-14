#include <iostream>
#include <vector>
using namespace std;

/*
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. 
Your task is to fix (or correct) the BST by swapping them back. Do not change the structure 
of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be 
wrong. All changes must be reflected in the original Binary search tree(BST).
*/

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inOrder(Node* root, vector<int>& order) {
    if (!root) return;
    
    inOrder(root -> left, order);
    order.push_back(root -> data);
    inOrder(root -> right, order);
}

void correctBSTUtil(Node* root, vector<int>& order, int& index) {
    if (!root) return;
    
    correctBSTUtil(root -> left, order, index);
    root -> data = order[index];
    index++;
    correctBSTUtil(root -> right, order, index);
}

void correctBSTOptimal(Node* root, Node* &first, Node* &middle, Node* &last, Node* &prev) {
    if (!root) return;
    
    correctBSTOptimal(root -> left, first, middle, last, prev);
    
    if (prev && root -> data < prev -> data) {
        
        if (!first) {
            first = prev;
            middle = root;
        } else last = root; 
        
    }
    prev = root;
    
    correctBSTOptimal(root -> right, first, middle, last, prev);
}

void correctBST(Node* root) {
    // Naive Approach O (n log n)
    // vector<int> order;
    // inOrder(root, order);
    // sort(begin(order), end(order));
    // int ind = 0;
    // correctBSTUtil(root, order, ind);
    
    Node *first = nullptr, *middle = nullptr, 
     *last = nullptr, *prev = nullptr;
    correctBSTOptimal(root, first, middle, last, prev);
    
    if (first && last) swap(first -> data, last -> data);
    else if (first && middle) swap(first -> data, middle -> data);
}

int main() {
    
    return 0;
}