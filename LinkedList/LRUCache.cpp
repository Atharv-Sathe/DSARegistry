#include <iostream>
#include <unordered_map>
using namespace std;


class Node{
  public:
  int key;
  int val;
  Node* prev;
  Node* next;

  Node(int key, int val): key(key), val(val) {}
};

Node* head = new Node(-1, -1);
Node* tail = new Node(-1, -1);
int capacity;
unordered_map<int, Node*> map;

void addNode(Node* newNode) {
  Node* temp = head -> next;
  newNode -> next = temp;
  newNode -> prev = head;

  head -> next = newNode;
  temp -> prev = newNode;
}

void deleteNode(Node* delNode) {
  Node* prevv = delNode -> prev;
  Node* nextt = delNode -> next;
  prevv -> next = nextt;
  nextt -> prev = prevv;
}

// LRUCache(int capacity): capacity(capacity) {
//   head -> next = tail;
//   tail -> prev = head;
// }

int get(int key) {
  if (map.count(key)) {
      Node* resNode = map[key];
      int ans = resNode -> val;
      
      deleteNode(resNode);
      addNode(resNode);
      map[key] = head -> next;
      return ans;
  }
  return -1;
}

void put(int key, int value) {
  if (map.count(key)) {
      Node* curr = map[key];
      deleteNode(curr);
      map.erase(key);
  }

  if (map.size() >= capacity) {
      map.erase(tail -> prev -> key);
      deleteNode(tail -> prev);
  }

  addNode(new Node(key, value));
  map[key] = head -> next;
}

int main() {
  
  return 0;
}