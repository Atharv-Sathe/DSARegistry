#include <iostream>
#include <vector>
using namespace std;

/*
Given a rod of length n(size of price) inches and an array of prices, price. 
price[i] denotes the value of a piece of length i. Determine the maximum value 
obtainable by cutting up the rod and selling the pieces.
*/

int getMaxProf(vector<int>& price, int ind, int curLen, vector<vector<int>>& dp) {
    if (curLen == price.size() || ind == price.size()) return 0;
    if (dp[ind][curLen] != -1) return dp[ind][curLen];
    
    int use = (curLen + ind + 1 <= price.size()) ? price[ind] + getMaxProf(price, ind, curLen + ind + 1, dp) : 0;
    int noUse = getMaxProf(price, ind + 1, curLen, dp);
    
    return dp[ind][curLen] = max(use, noUse);
}

int getMaxProfTab(vector<int>& price) {
    int n = price.size();
    vector<int> dp(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int len = i + 1; len <= n; len++) {
            dp[len] = max(dp[len], price[i] + dp[len - i - 1]);
        }
    }
    return dp[n];
}

int cutRod(vector<int> &price) {
    // Constraints:
    /*
        1. Sum of lengths of pieces == price.size()
        2. Maximize the profit
    */
    // vector<vector<int>> dp(price.size(), vector<int>(price.size(), -1));
    // return getMaxProf(price, 0, 0, dp);
    
    return getMaxProfTab(price); 
}

int main() {
  
  return 0;
}