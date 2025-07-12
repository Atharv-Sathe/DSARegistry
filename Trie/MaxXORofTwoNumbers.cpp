#include <bits/stdc++.h>
using namespace std;

/*
  Given an integer array nums, return the maximum result of nums[i] XOR nums[j], 
  where 0 <= i <= j < n.
*/

class Solution {
private:
    struct Trie {
        Trie* links[2];
        bool isEnd = false;

        Trie () {
            links[0] = nullptr;
            links[1] = nullptr;
        }

        bool isEmpty() {
            return !links[0] && !links[1];
        }

        void insert(int num) {
            Trie* node = this;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (!(node -> links[bit])) {
                    Trie* newNode = new Trie();
                    node -> links[bit] = newNode;
                }
                node = node -> links[bit];
            }
            node -> isEnd = true;
        }

        int findMaxXOR(int num) {
            long long XOR = 0;
            Trie* node = this;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                // If opp bit available at this level then add it's contribution else add 0
                if (node -> links[!bit]) {
                    XOR |= (1 << i);
                    node = node -> links[!bit];
                } else {
                    node = node -> links[bit];
                }
            }
            return XOR;
        }
    };


public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        long long maxXOR = 0;
        for (int i : nums) {
            bitset<32> b(i);
            int num = b.to_ulong();
            trie.insert(num);
            long long curXOR = trie.findMaxXOR(num);
            maxXOR = max(maxXOR, curXOR);
        }
        return maxXOR;
    }
};

int main() {
  
  return 0;
}