#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
You are given two strings s1 and s2. Your task is to find the length of the 
longest common substring among the given strings.
*/
    
// Brute Force
// Generate all substrings
void getAllSubstrings(set<string>& res, string& s1) {
    for (int i = 0; i < s1.length(); i++) {
        string temp = "";
        for (int j = i; j < s1.length(); j++) {
            temp += s1[j];
            res.insert(temp);
        }
    }
}

// Tabulation
int getLgstCmnSustrLen(string& s1, string& s2) {
    
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    int maxLen = INT_MIN;
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = 0;
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    
    return maxLen;
}


int longestCommonSubstr(string& s1, string& s2) {
    // Brute Force TC : O(n^2 log n)
    // set<string> set1, set2;
    // getAllSubstrings(set1, s1);
    // getAllSubstrings(set2, s2);
    
    // vector<string> res;
    // set_intersection(begin(set1), end(set1), begin(set2), end(set2), back_inserter(res));
    
    // if (!res.size()) return 0;
    
    // string longestCommonSubStr = *max_element(res.begin(), res.end(), [](const string& s1, const string& s2) {
    //     return s1.length() < s2.length();
    // });
    
    // return longestCommonSubStr.length();
    
    // Tabulation TC: O(n * m);
    return getLgstCmnSustrLen(s1, s2);
}

int main() {
  
  return 0;
}