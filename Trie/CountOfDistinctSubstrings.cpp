#include <bits/stdc++.h>
using namespace std;

/*
  Given a string of length N of lowercase alphabet characters. The task is to
  complete the function countDistinctSubstring(), which returns the count of
  total number of distinct substrings of this string.
*/

struct Trie {
  Trie* links[26] = {nullptr};
  bool isEnd = false;

  Trie() {
    for (int i = 0; i < 26; i++) {
      links[i] = nullptr;
    }
  }

  ~Trie() {
    for (int i = 0; i < 26; i++) {
      delete links[i];
    }
  }

  bool hasLink(char ch) { return links[ch - 'a'] != nullptr; }

  Trie* getLink(char ch) { return links[ch - 'a']; }

  void setLink(char ch, Trie* node) { links[ch - 'a'] = node; }

  void setEnd() { isEnd = true; }

  void insert(string& word) {
    Trie* node = this;
    for (int i = 0; i < word.size(); i++) {
      if (!node->hasLink(word[i])) {
        Trie* newNode = new Trie();
        node->setLink(word[i], newNode);
      }
      node = node->getLink(word[i]);
    }
    node->setEnd();
  }

  int countNodesIterative() {
    int count = 0;
    queue<Trie*> q;

    for (int i = 0; i < 26; i++) {
      if (this->links[i]) {
        q.push(this->links[i]);
        count++;
      }
    }

    while (!q.empty()) {
      Trie* curr = q.front();
      q.pop();

      for (int i = 0; i < 26; i++) {
        if (curr->links[i]) {
          q.push(curr->links[i]);
          count++;
        }
      }
    }

    return count;
  }
};

int countDistinctSubstring(string s) {
  Trie* trie = new Trie();

  for (int i = 0; i < s.size(); i++) {
    string temp = s.substr(i);
    trie->insert(temp);
  }

  int distinctSubstr = trie->countNodesIterative();

  delete trie;  // It was important to delete trie before returning to prevent
                // mem limit

  return distinctSubstr + 1;
}

int main() { return 0; }