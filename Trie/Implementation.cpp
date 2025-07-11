#include <bits/stdc++.h>
using namespace std;

class Trie {
 private:
  struct TrieNode {
    TrieNode* links[26];
    bool isEnd = false;

    bool hasLink(char ch) { return links[ch - 'a'] ? true : false; }

    TrieNode* getLink(char ch) { return links[ch - 'a']; }

    void setLink(char ch, TrieNode* node) { links[ch - 'a'] = node; }

    void setEnd() { isEnd = true; }

    bool isWordEnd() { return isEnd; }
  };
  TrieNode* root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i]))) {
        // Create a new link at this position
        TrieNode* newNode = new TrieNode();
        node->setLink(word[i], newNode);
      }
      // Move to the next link
      node = node->getLink(word[i]);
    }
    node->setEnd();
  }

  bool search(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i])))
        return false;
      else {
        node = node->getLink(word[i]);
      }
    }
    return node->isWordEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (!(node->hasLink(prefix[i])))
        return false;
      else
        node = node->getLink(prefix[i]);
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() { return 0; }