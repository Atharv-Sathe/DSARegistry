// Return the pointer which is the start of the cycle.

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if (!head || !head -> next) return nullptr;
    // set<ListNode*> pointersTraversed;
    // ListNode *slow = head;
    // while(slow -> next) {
    //     if (pointersTraversed.count(slow)) return slow; 
    //     pointersTraversed.insert(slow);
    //     slow = slow -> next;
    // }
    // return nullptr;

    // Optimized
    ListNode *fast = head, *slow = head;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if (fast == slow) {
            slow = head;
            while (slow != fast) {
                fast = fast -> next;
                slow = slow -> next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    
    return 0;
}
