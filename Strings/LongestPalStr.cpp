#include <bits/stdc++.h>
using namespace std;

// bool isPal(string s) {
//     int l = 0, r = s.size() - 1;
//     while(l < r) {
//         if (s[l] != s[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }

void checkPal(string &ans, int &maxLen, string &s, int l, int r) {
    while(l >= 0 && r < s.size() && s[l] == s[r]) {
        string subStr = s.substr(l, r - l + 1);
        int len = subStr.size();
        if (len > maxLen) {
            ans = subStr;
            maxLen = len;
        }
        l--;
        r++;
    }
}

string longestPalindrome(string s) {
    // Brute Force | O(n^3)
    int maxLen = INT_MIN;
    string ans = "";
    // for(int i = 0; i < s.size(); i++) {
    //     for (int j = i; j < s.size(); j++) {
    //         string subStr = s.substr(i, j - i + 1);
    //         int len = subStr.size();
    //         if (isPal(subStr)) {
    //             if (maxLen < len) {
    //                 ans = subStr;
    //                 maxLen = len;
    //             }
    //         }
    //     }
    // }
    // return ans;
    
    for (int i = 0; i < s.size(); i++) {
        checkPal(ans, maxLen, s, i, i);
        checkPal(ans, maxLen, s, i, i + 1);
    }
    return ans;
}

int main() {
    
    string s = "babad";
    cout << longestPalindrome(s) << endl;

    return 0;
}