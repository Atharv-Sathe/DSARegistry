#include <bits/stdc++.h>
using namespace std;
/*
A new alien language uses the English alphabet, but the order of letters is
unknown. You are given a list of words[] from the alien language’s dictionary,
where the words are claimed to be sorted lexicographically according to the
language’s rules.

Your task is to determine the correct order of letters in this alien language
based on the given words. If the order is valid, return a string containing the
unique letters in lexicographically increasing order as per the new language's
rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible
letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first
position where they differ, the character in a appears earlier in the alien
language than the corresponding character in b. If all characters in the shorter
word match the beginning of the longer word, the shorter word is considered
smaller.

Note: Your implementation will be tested using a driver code. It will print true
if your returned order correctly follows the alien language’s lexicographic
rules; otherwise, it will print false.
*/

string findOrder(vector<string>& words) {
  vector<vector<char>> adjList(26);
  vector<int> indegree(26, 0);
  vector<bool> hasLetter(26, false);  // To find the letters in words

  // Collecting all letters
  for (const string& word : words) {
    for (char c : word) {
      hasLetter[c - 'a'] = true;
    }
  }

  // Build Graph
  for (int i = 0; i < words.size() - 1; i++) {
    const string& word1 = words[i];
    const string& word2 = words[i + 1];

    int minLen = min(word1.size(), word2.size());
    bool foundDiff = false;

    for (int j = 0; j < minLen; j++) {
      if (word1[j] != word2[j]) {
        int u = word1[j] - 'a';
        int v = word2[j] - 'a';
        adjList[u].push_back(v);
        indegree[v]++;
        foundDiff = true;
        break;
      }
    }

    // If word1 is longer and no diff found
    if (!foundDiff && word1.size() > word2.size()) return "";
  }

  // Kahn's Algo
  queue<int> q;
  for (int i = 0; i < 26; i++) {
    if (hasLetter[i] && indegree[i] == 0) q.push(i);
  }

  string result;
  result.reserve(26);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    result += (char)('a' + node);

    for (int nbr : adjList[node]) {
      indegree[nbr]--;
      if (indegree[nbr] == 0) q.push(nbr);
    }
  }

  // Count total uniq chars
  int totalLetters = 0;
  for (int i = 0; i < 26; i++)
    if (hasLetter[i]) totalLetters++;

  return result.size() == totalLetters ? result : "";
}

int main() { return 0; }