#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    // Brute Force | O(n^2)
    // int maxLen = 0;
    // int maxFreq;
    // for (int i = 0; i < s.size(); i++) {
    //     int hash[26] = {0};
    //     maxFreq = 0;
    //     for (int j = i; j < s.size(); j++) {
    //         hash[s[j] - 'A']++;
    //         maxFreq = max(maxFreq, hash[s[j] - 'A']);
    //         int changes = j - i + 1 - maxFreq;
    //         if (changes <= k) {
    //             maxLen = max(maxLen, j - i + 1);
    //         } else {
    //             break;
    //         }    
    //     }
    // }
    // return maxLen;

    int l = 0, r = 0, maxFreq = 0, maxLen = 0;
    int hash[26] = {0};
   
    while (r < s.size()) {
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);

        if (( r - l + 1) - maxFreq > k) {
            hash[s[l] - 'A']--; maxFreq = 0;
            // for (int i = 0; i < 26; i++) maxFreq = max(maxFreq, hash[i]);
            l += 1; 
        }

        if ((r - l + 1) - maxFreq <= k) maxLen = max(maxLen, r - l + 1);
        r++;
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