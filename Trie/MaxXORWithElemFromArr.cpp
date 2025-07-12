#include <bits/stdc++.h>
using namespace std;

/*
  You are given an array nums consisting of non-negative integers. You are also
  given a queries array, where queries[i] = [xi, mi].

  The answer to the ith query is the maximum bitwise XOR value of xi and any
  element of nums that does not exceed mi. In other words, the answer is
  max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums
  are larger than mi, then the answer is -1.

  Return an integer array answer where answer.length == queries.length and
  answer[i] is the answer to the ith query.
*/

class Solution {
 private:
  struct Trie {
    Trie* links[2];
    bool isEnd = false;

    Trie() {
      links[0] = nullptr;
      links[1] = nullptr;
    }

    bool isEmpty() { return !links[0] && !links[1]; }

    void insert(int num) {
      Trie* node = this;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!(node->links[bit])) {
          Trie* newNode = new Trie();
          node->links[bit] = newNode;
        }
        node = node->links[bit];
      }
      node->isEnd = true;
    }

    int findMaxXOR(int num) {
      long long XOR = 0;
      Trie* node = this;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        // If opp bit available at this level then add it's contribution else
        // add 0
        if (node->links[!bit]) {
          XOR |= (1 << i);
          node = node->links[!bit];
        } else {
          node = node->links[bit];
        }
      }
      return XOR;
    }
  };

 public:
  vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> indices(queries.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(),
         [&queries](int a, int b) { return queries[a][1] < queries[b][1]; });

    sort(nums.begin(), nums.end());

    vector<int> result(queries.size());
    Trie trie;
    int numIndex = 0;

    for (int i = 0; i < indices.size(); i++) {
      int queryIndx = indices[i];
      int x = queries[queryIndx][0];
      int m = queries[queryIndx][1];

      // Building trie with numbers <= m
      while (numIndex < nums.size() && nums[numIndex] <= m) {
        trie.insert(nums[numIndex]);
        numIndex++;
      }

      if (trie.isEmpty())
        result[queryIndx] = -1;
      else {
        int maxXOR = trie.findMaxXOR(x);
        result[queryIndx] = maxXOR;
      }
    }
    return result;
  }
};

int main() { return 0; }