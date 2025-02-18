#include <iostream>
#include <unordered_map>
using namespace std;

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, 
returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the 
key if not already present. When the cache reaches its capacity, it should invalidate 
and remove the least frequently used key before inserting a new item. For this problem, 
when there is a tie (i.e., two or more keys with the same frequency), the least recently 
used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in 
the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the 
put operation). The use counter for a key in the cache is incremented either a get or 
put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

class LFUCache {
private:
    class Node {
    public:
        int key, val, freq;
        Node* prev;
        Node* next;
        Node(int key, int val): key(key), val(val), freq(1) {}
    };

    class DL {
    public:
        Node* head;
        Node* tail;

        DL() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void addNode(Node* newNode) {
            Node* temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
        }

        void removeNode(Node* remNode) {
            remNode->prev->next = remNode->next;
            remNode->next->prev = remNode->prev;
        }

        bool isEmpty() {
            return head->next == tail;
        }
    };

    unordered_map<int, Node*> keyNode;
    unordered_map<int, DL*> freqList;
    int minFreq;
    int capacity;

    void updateNode(Node* upNode) {
        int oldFreq = upNode->freq;
        freqList[oldFreq]->removeNode(upNode);
        if (freqList[oldFreq]->isEmpty()) {
            freqList.erase(oldFreq);
            if (oldFreq == minFreq) minFreq++;
        }
        upNode->freq++;
        if (!freqList.count(upNode->freq)) {
            freqList[upNode->freq] = new DL();
        }
        freqList[upNode->freq]->addNode(upNode);
    }

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        if (!keyNode.count(key)) return -1;
        Node* resNode = keyNode[key];
        updateNode(resNode);
        return resNode->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyNode.count(key)) {
            Node* resNode = keyNode[key];
            resNode->val = value;
            updateNode(resNode);
        } else {
            if (keyNode.size() >= capacity) {
                DL* leastFreqList = freqList[minFreq];
                Node* leastFreqNode = leastFreqList->tail->prev;
                keyNode.erase(leastFreqNode->key);
                leastFreqList->removeNode(leastFreqNode);
                if (leastFreqList->isEmpty()) freqList.erase(minFreq);
                delete leastFreqNode;
            }
            Node* newNode = new Node(key, value);
            keyNode[key] = newNode;
            minFreq = 1;
            if (!freqList.count(minFreq)) {
                freqList[minFreq] = new DL();
            }
            freqList[minFreq]->addNode(newNode);
        }
    }
};

int main() {
  
  return 0;
}