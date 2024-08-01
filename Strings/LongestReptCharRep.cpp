#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    // Brute Force | O(n^2)
    int maxLen = 0;
    int maxFreq;
    for (int i = 0; i < s.size(); i++) {
        int hash[128] = {0};
        maxFreq = 0;
        for (int j = i; j < s.size(); j++) {
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq, hash[s[j] - 'A']);
            int changes = j - i + 1 - maxFreq;
            if (changes <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break;
            }    
        }
    }
    return maxLen;
}

int main() {
    
    string s;
    // s = "ABAB";
    // s = "AABABBA";
    // s ="AAAB";
    s = "ABBB";
    int k = 2;
    cout << characterReplacement(s, k) << endl;

    return 0;
}