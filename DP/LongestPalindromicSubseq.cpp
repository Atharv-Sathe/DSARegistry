#include <iostream>
#include <vector>
using namespace std;

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
without changing the order of the remaining elements.
*/

    int memoization(string& s, int i, int j, vector<vector<int>>& memo) {
        if (i == j) return 1; // single character is palindromic
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == s[j]) {
            return memo[i][j] = 2 + memoization(s, i + 1, j - 1, memo);
        } 
        
        return memo[i][j] = max(memoization(s, i + 1, j, memo), memoization(s, i, j - 1, memo));
    }

    int tabulation(string& s) {
        int n = s.length();
        vector<vector<int>> tab(n, vector<int>(n, 0));
        int i = -1;
        while (++i < n) tab[i][i] = 1;
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    tab[i][j] = 2 + (len > 2 ? tab[i+1][j-1] : 0);
                } else {
                    tab[i][j] = max(tab[i+1][j], tab[i][j-1]);
                }
            }
        }

        return tab[0][n - 1];
    }


    int longestPalindromeSubseq(string s) {
        // vector<vector<int>> memo(s.length(), vector<int>(s.length(), -1));
        // return memoization(s, 0, s.length() - 1, memo);

        return tabulation(s);
    }

int main() {
  
  return 0;
}