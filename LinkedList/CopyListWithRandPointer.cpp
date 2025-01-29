#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// T(n) and O(1)
Node* copyRandomList(Node* head) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (!head) return head;
    
    // Interveawe the two lists
    Node* curr = head;
    while(curr) {
        Node* copy = new Node(curr -> val);
        copy -> next = curr -> next;
        curr -> next = copy;
        curr = copy -> next;
    }

    // Attach random pointers
    curr = head;
    while(curr) {
        if (curr -> random) {
            curr -> next -> random = curr -> random -> next;
        }
        curr = curr -> next -> next;
    }

    // Seperate Lists
    Node* deepCopy = head -> next;
    curr = head;
    while(curr) {
        Node* copy = curr -> next;
        curr -> next = copy -> next;
        if (copy -> next) {
            copy -> next = copy -> next -> next;
        }
        curr = curr -> next;
    }
    return deepCopy;
}

int main() {
    
    return 0;
}