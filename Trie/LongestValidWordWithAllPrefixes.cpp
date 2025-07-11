#include <bits/stdc++.h>
using namespace std;

/*
  Given an array of strings words[], find the longest string such that every prefix of 
  it is also present in words[]. If multiple strings have the same maximum length, 
  return the lexicographically smallest one.

  If no such string is found, return an empty string.
*/


struct Trie {
  Trie* links[26];
  bool isEnd = false;

  // Helper Function
  bool hasLink(char ch) { return links[ch - 'a'] != nullptr ? true : false; }

  void setLink(char ch, Trie* node) { links[ch - 'a'] = node; }

  Trie* getLink(char ch) { return links[ch - 'a']; }

  void setEnd() { isEnd = true; }

  void insert(string& word) {
    Trie* node = this;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i]))) {
        Trie* newNode = new Trie();
        node->setLink(word[i], newNode);
      }
      node = node->getLink(word[i]);
    }
    node->setEnd();
  }

  void recurse(string& cur, string& maxLenString) {
    if (!isEnd) return;

    if ((cur.size() > maxLenString.size()) ||
        (cur.size() == maxLenString.size() && cur < maxLenString)) {
      maxLenString = cur;
    }

    for (int i = 0; i < 26; i++) {
      if (links[i] && links[i]->isEnd) {
        cur += (char)('a' + i);
        links[i]->recurse(cur, maxLenString);
        cur.pop_back();
      }
    }
  }

  string findLongestValidWord() {
    string ans = "", cur = "";
    for (int i = 0; i < 26; ++i) {
      if (links[i] && links[i]->isEnd) {
        cur += (char)('a' + i);
        links[i]->recurse(cur, ans);
        cur.pop_back();
      }
    }
    return ans;
  }
};

string longestValidWord(vector<string>& words) {
  // code here

  // TC : O(n * m)
  // unordered_set<string> stringSet(words.begin(), words.end());

  // string maxLenString = "";
  // for (const auto& word : words) {
  //     bool canBe = true;
  //     string temp = "";
  //     for (int i = 0; i < word.size(); i++) {
  //         temp += word[i];
  //         if (!stringSet.count(temp)) {
  //             canBe = false;
  //             break;
  //         }
  //     }

  //     if (canBe) {
  //         if (word.size() > maxLenString.size()) {
  //             maxLenString = word;
  //         } else if (word.size() == maxLenString.size()) {
  //             maxLenString = min(maxLenString, word);
  //         }
  //     }
  // }
  // return maxLenString;

  Trie* trie = new Trie();

  for (auto& word : words) {
    trie->insert(word);
  }

  return trie->findLongestValidWord();
}

int main() { return 0; }