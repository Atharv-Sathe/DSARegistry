#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* start, int k) {
    ListNode* prev = nullptr;
    ListNode* curr = start;
    ListNode* tempN = nullptr;
    while(k--) {    
        tempN = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = tempN;
    }
    start -> next = tempN;
    return prev;
}

int getLength(ListNode* head) {
    int length = 0;
    while(head) {
        head = head -> next;
        length++;
    }
    return length;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    int length = getLength(head);
    if (length < k) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy -> next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    ListNode* next = nullptr;

    for (int i = 0; i + k <= length; i += k) {
        curr = prev -> next;
        next = curr;
        for (int j = 0; j < k; j++) {
            next = next -> next;
        }

        ListNode* newHead = reverse(curr, k);
        prev -> next = newHead;
        curr -> next = next;
        prev = curr;
        curr = next;
    }
    return dummy -> next;
}

int main() {
    
    

    return 0;
}