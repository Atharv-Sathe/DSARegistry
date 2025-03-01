#include <iostream>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

    vector<int> postOrder(Node* node) {
        vector<int> order;
        stack<Node*> st;
        unordered_set<Node*> visited;
        st.push(node);
        visited.insert(node);
        while(!st.empty()) {
            Node* curr = st.top();
            if (!curr -> right && !curr -> left) {
                order.push_back(curr -> data);
                st.pop();
            } else {
                if (curr -> right && !visited.count(curr -> right)) {
                    st.push(curr -> right);
                    visited.insert(curr -> right);
                };
                if (curr -> left && !visited.count(curr -> left)) {
                    st.push(curr -> left);
                    visited.insert(curr -> left);
                }
                
                // If nothing is pushed pop the top
                if (curr == st.top()) {
                    st.pop();
                    order.push_back(curr -> data);
                }
            }
        }
        return order;
    }

int main() {
  return 0;
}
