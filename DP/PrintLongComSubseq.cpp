#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/*
Given two strings text1 and text2, print their longest common 
subsequence. If there is no common subsequence, print "".

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
string getLongestSubseq(string& text1, string& text2, int i, int j, vector<vector<string>>& dp) {
  if (i >= text1.size() || j >= text2.size()) return "";
  if (dp[i][j] != "#") return dp[i][j];

  if (text1[i] == text2[j]) return text1[i] + getLongestSubseq(text1, text2, i + 1, j + 1, dp);

  string res1 = getLongestSubseq(text1, text2, i + 1, j, dp);
  string res2 = getLongestSubseq(text1, text2, i, j + 1, dp);

  return dp[i][j] = (res1.length() > res2.length()) ? res1 : res2;
}

// Tabulation
string getLongestSubseqTab(string& text1, string& text2) {
  int n = text1.length(), m = text2.length();
  vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));

  for (int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) dp[i][j] = text1[i - 1] + dp[i - 1][j - 1];
          else {
            string res1 = dp[i - 1][j];
            string res2 = dp[i][j - 1];
            dp[i][j] = (res1.length() > res2.length()) ? res1 : res2;
          };
      }
  }
  
  reverse(dp[n][m].begin(), dp[n][m].end());
  return dp[n][m];
}

// Tabulation Space Op
string getLongestSubseqTabSpaceOp(string& text1, string& text2) {
  int n = text1.length(), m = text2.length();
  vector<string> prev(m + 1, ""), curr(m + 1, "");

  for (int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
          if (text1[i - 1] == text2[j - 1]) curr[j] = text1[i - 1] + prev[j - 1];
          else {
            string res1 = prev[j];
            string res2 = curr[j - 1];
            curr[j] = (res1.length() > res2.length()) ? res1 : res2;
          };
      }
      prev = curr;
  }

  reverse(curr[m].begin(), curr[m].end());
  return curr[m];
}

void longestCommonSubsequence(string text1, string text2) {

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
  // cout << longestSubseq << endl;
  // return longestSubseq.length();

  // Memoization
  // int n = text1.length(), m = text2.length();
  // vector<vector<string>> dp(n, vector<string>(m, "#"));
  // cout << getLongestSubseq(text1, text2, 0, 0, dp) << endl;

  // Tabulation
  // cout << getLongestSubseqTab(text1, text2) << endl;

  // Space Optimized Tabulation
  cout << getLongestSubseqTabSpaceOp(text1, text2) << endl;    
}

int main() {
  string text1 = "abcde", text2 = "ace";
  longestCommonSubsequence(text1, text2);
  return 0;
}