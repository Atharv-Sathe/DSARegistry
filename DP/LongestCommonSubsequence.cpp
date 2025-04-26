#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
Given two strings text1 and text2, return the length of their longest common 
subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string 
with some characters (can be none) deleted without changing the relative order 
of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

// Can actually print the largest common subsequence
set<string> getAllSubseqs(string& text, int ind, const string& curStr) {
  if (ind == text.length()) return {curStr};

  // All Subseqs without involving the current index
  set<string> subseqs = getAllSubseqs(text, ind + 1, curStr);
  // All Subseqs involving the current index
  set<string> include = getAllSubseqs(text, ind + 1, curStr + text[ind]);
  subseqs.insert(include.begin(), include.end());
  return subseqs;
}

// Memoization
int getLongestSubseq(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
  if (i >= text1.size() || j >= text2.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (text1[i] == text2[j]) return 1 + getLongestSubseq(text1, text2, i + 1, j + 1, dp);

  return dp[i][j] = max(getLongestSubseq(text1, text2, i + 1, j, dp), getLongestSubseq(text1, text2, i, j + 1, dp));
}

// Tabulation
int getLongestSubseqTab(string& text1, string& text2) {
  int n = text1.length(), m = text2.length();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
  }

  return dp[n][m];
}

// Tabulation Space Op
int getLongestSubseqTabSpaceOp(string& text1, string& text2) {
  int n = text1.length(), m = text2.length();
  vector<int> prev(m + 1, 0), curr(m + 1, 0);

  for (int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
          else curr[j] = max(prev[j], curr[j - 1]);
      }
      prev = curr;
  }

  return curr[m];
}

int longestCommonSubsequence(string text1, string text2) {

  // This Solution works but leads to a huge memory overhead
  // causing memory limit exceeded error
  // set<string> text1Subseqs = getAllSubseqs(text1, 0, "");
  // set<string> text2Subseqs = getAllSubseqs(text2, 0, "");
  // vector<string> result;
  // set_intersection(text1Subseqs.begin(), text1Subseqs.end(), text2Subseqs.begin(),text2Subseqs.end(), back_inserter(result));
  
  // auto comp = [](const string& a, const string& b) {
  //     return a.length() < b.length();
  // };

  // string longestSubseq = *max_element(result.begin(), result.end(), comp);
  // return longestSubseq.length();

  // Memoization
  // int n = text1.length(), m = text2.length();
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // return getLongestSubseq(text1, text2, 0, 0, dp);

  // Tabulation
  // return getLongestSubseqTab(text1, text2);

  // Space Optimized Tabulation
  return getLongestSubseqTabSpaceOp(text1, text2);    
}

int main() {
  
  return 0;
}