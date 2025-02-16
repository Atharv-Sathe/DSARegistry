#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

/*
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).
*/

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node -> data = data;
  node -> left = node -> right = nullptr;
  return node;
}
void serializePreorder(Node* root, vector<int>& order) {
  if (!root) {
      order.push_back(-1);
      return;
  }
        
  order.push_back(root -> data);
  serializePreorder(root -> left, order);
  serializePreorder(root -> right, order);
}
    
Node* deserializePreorder(int& i, vector<int>& order) {
  if (order[i] == -1) {
      i++;
      return nullptr;
  }
        
  Node* root = newNode(order[i]);
  i++;
        
  root -> left = deserializePreorder(i, order);
  root -> right = deserializePreorder(i, order);
  return root;
}

// Function to serialize a tree and return a list containing nodes of tree.
vector<int> serialize(Node *root) {
  // Your code here
  vector<int> order;
  serializePreorder(root, order);
  return order;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &arr) {
  // Your code here
  int i = 0;
  return deserializePreorder(i, arr);
}


int main() {
  return 0;
}
