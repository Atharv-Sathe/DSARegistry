#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

/*
A transformation sequence from word beginWord to word endWord using a dictionary
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to
be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all
the shortest transformation sequences from beginWord to endWord, or an empty
list if no such sequence exists. Each sequence should be returned as a list of
the words [beginWord, s1, s2, ..., sk].
*/

// The below solution is not memory effecient
// since it stores the entire path in queue.
vector<vector<string>> method1(string beginWord, string endWord,
                                   vector<string>& wordList) {
  unordered_set<string> wordSet(all(wordList));
  // if endWord not in wordSet return an empty list
  if (!wordSet.count(endWord)) return {};

  queue<vector<string>> q;
  q.push({beginWord});
  vector<string> usedOnLevel{beginWord};
  int level = 0;
  vector<vector<string>> ans;
  while (!q.empty()) {
    vector<string> current = q.front();
    string word = current.back();
    q.pop();

    int levelSize = current.size();
    if (levelSize > level) {
      level++;
      // If we are on a higher level remove all the words that appeared on prev
      // level
      for (const string& s : usedOnLevel) {
        wordSet.erase(s);
      }
      usedOnLevel.clear();
    }

    if (word == endWord) {
      ans.push_back(current);
      break;
    }

    for (size_t i = 0; i < word.size(); i++) {
      char original = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        word[i] = c;

        if (wordSet.count(word)) {
          current.push_back(word);
          q.push(current);
          current.pop_back();
          usedOnLevel.push_back(word);
        }
      }
      word[i] = original;
    }
  }

  int minSize;
  if (!ans.empty()) minSize = ans.back().size();
  while (!q.empty()) {
    vector<string> curSeq = q.front();
    q.pop();
    if (curSeq.size() > minSize)
      break;
    else if (curSeq.back() == endWord)
      ans.push_back(curSeq);
  }

  return ans;
}

// Memory Effecient Version passes on leetcode
vector<vector<string>> method2(string beginWord, string endWord,
                               vector<string>& wordList) {
  unordered_set<string> wordSet(all(wordList));
  unordered_map<string, int> stringToLevel;
  queue<string> q;
  q.push(beginWord);
  wordSet.erase(beginWord);
  int level = 0;
  while (!q.empty()) {
    int levelSize = q.size();
    int currentLevel = stringToLevel[q.front()];

    for (int j = 0; j < levelSize; j++) {
      auto currentWord = q.front();
      q.pop();
      if (currentWord == endWord) break;

      // Generate all possible patterns on fly by
      for (size_t i = 0; i < currentWord.size(); i++) {
        char original = currentWord[i];
        for (char c = 'a'; c <= 'z'; c++) {
          currentWord[i] = c;

          if (wordSet.count(currentWord)) {
            stringToLevel[currentWord] = currentLevel + 1;
            q.push(currentWord);
            wordSet.erase(currentWord);
          }
        }
        currentWord[i] = original;
      }
    }
  }

  vector<string> seq{endWord};
  vector<vector<string>> ans;
  function<void(string&)> dfs = [&](string& word) {
    if (word == beginWord) {
      ans.push_back(seq);
    }
    string originalWord = word;
    // Generate all the patterns
    for (size_t i = 0; i < word.size(); i++) {
      char original = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        word[i] = c;

        if (stringToLevel.count(word) &&
            stringToLevel[word] + 1 == stringToLevel[originalWord]) {
          seq.push_back(word);
          dfs(word);
          seq.pop_back();
        }
      }
      word[i] = original;
    }
  };

  dfs(endWord);
  // reverse all lists in ans
  for (auto& list : ans) {
    reverse(all(list));
  }

  return ans;
}

int main() { return 0; }