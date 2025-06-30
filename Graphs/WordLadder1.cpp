#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

/*
  NOTE : It is important to note that the solution below provides a way to solve the
  question in three time complexities:
  1. O(N^2 * M) : Use this when N is shorter than M
  2. O(N * M^2) : Use this when M is shorter and < 26
  3. O(N * M * 26) : Use this when M is > 26
*/

/*
A transformation sequence from word beginWord to word endWord using a dictionary 
wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to 
be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the 
number of words in the shortest transformation sequence from beginWord to endWord, 
or 0 if no such sequence exists.
*/

// Checks if two words differ by exactly one character
bool diffByOne(string& a, string& b) {
  if (a.size() != b.size()) return false;
  int n = a.size();
  int difCount = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) difCount++;
    if (difCount > 1) return false;
  }
  return true;
}

// Builds an adjacency list where an edge exists if words differ by one letter
vector<vector<int>> buildGraph(vector<string>& allWords) {
  int nodeCount = allWords.size();

  // Building the adjacency matrix
  vector<vector<int>> adj(nodeCount);

  for (int i = 0; i < nodeCount; i++) {
    for (int j = i + 1; j < nodeCount; j++) {
      if (i == j) continue;

      if (diffByOne(allWords[i], allWords[j])) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  return adj;
}

// Standard BFS to find shortest path from start to key in the adjacency list
int bfs(int start, int key, vector<vector<int>>& adj) {
  int nodeCount = adj.size();
  vector<bool> visited(nodeCount, false);

  queue<int> q;
  q.push(start);
  visited[start] = true;

  int stepCount = 0;
  while (!q.empty()) {
    int levelSize = q.size();
    stepCount++;
    for (int i = 0; i < levelSize; i++) {
      int node = q.front();
      q.pop();
      if (node == key) return stepCount;
      for (int nbr : adj[node]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }
  return 0;
}

// Less optimal approach: builds the full graph and runs BFS
int method1(string& beginWord, string& endWord,
                        vector<string>& wordList) {
  int start = 0;
  // Only add the begin word to wordList if not already there.
  auto itB = find(all(wordList), beginWord);
  if (itB != wordList.end()) {
    start = itB - wordList.begin();
  } else {
    wordList.push_back(beginWord);
    start = wordList.size() - 1;
  }

  // If endWord not in wordList return 0
  auto it = find(all(wordList), endWord);
  if (it == wordList.end()) return 0;

  vector<vector<int>> adj = buildGraph(wordList);

  int endNode = it - wordList.begin();
  int n = wordList.size();
  int cost = bfs(start, endNode, adj);
  return cost;
}

// BFS using pattern mapping for optimization
int bfsPatternBased(string& beginWord, string& endWord,
                    unordered_map<string, vector<string>>& patternMap) {
  queue<string> q;
  unordered_set<string> visited;

  q.emplace(beginWord);
  visited.insert(beginWord);
  int level = 1;
  while (!q.empty()) {
    int levelSize = q.size();

    for (int i = 0; i < levelSize; i++) {
      string currentWord = q.front();
      q.pop();

      if (currentWord == endWord) return level;

      // For each position, replace with '*' and check all matching words
      for (size_t j = 0; j < currentWord.size(); j++) {
        string pattern = currentWord;
        pattern[j] = '*';

        for (const string& nbr : patternMap[pattern]) {
          if (!visited.count(nbr)) {
            q.emplace(nbr);
            visited.insert(nbr);
          }
        }
      }
    }

    level++;
  }

  return 0;
}

// Optimal approach: uses pattern mapping to reduce search space
int method2(string& beginWord, string& endWord, vector<string>& wordList) {
  unordered_set<string> wordSet(all(wordList));
  if (!wordSet.count(endWord)) return 0;

  wordSet.insert(beginWord);

  unordered_map<string, vector<string>> patternMap;

  // Build pattern map: for each word, replace each letter with '*' to form patterns
  for (const string& word : wordSet) {
    for (int i = 0; i < word.size(); i++) {
      string pattern = word;
      pattern[i] = '*';
      patternMap[pattern].emplace_back(word);
    }
  }

  return bfsPatternBased(beginWord, endWord, patternMap);
}

int method3(string& beginWord, string& endWord, vector<string>& wordList) {
  unordered_set<string> wordSet(all(wordList));

  queue<pair<string, int>> q;
  q.push({beginWord, 1});
  wordSet.erase(beginWord);

  while(!q.empty()) {
    auto [currentWord, step] = q.front();
    q.pop();

    if (currentWord == endWord) return step;

    // Generate all possible patterns on fly by
    for (size_t i = 0; i < currentWord.size(); i++) {
      char original = currentWord[i];
      for (char c = 'a'; c <= 'z'; c++) {
        currentWord[i] = c;

        if (wordSet.count(currentWord)) {
          q.push({currentWord, step + 1});
          wordSet.erase(currentWord);
        }
      }
      currentWord[i] = original;
    }
  }
  return 0;
}

// Main function to solve the Word Ladder problem
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  // TC : O(N^2 * M)
  // return method1(beginWord, endWord, wordList);

  // TC : O(N * M^2)
  // return method2(beginWord, endWord, wordList);

  // TC: O(N * M * 26)
  return method3(beginWord, endWord, wordList);
}

int main() { return 0; }