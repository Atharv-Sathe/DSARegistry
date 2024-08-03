#include <bits/stdc++.h>
using namespace std;

    // bool isValSub(string s, unordered_map<char, int> map) {
    //     for (char c: s) {
    //         if (map.count(c) != 0) map[c]--;
    //         if (map[c] == 0) map.erase(c);
    //     }
    //     return map.empty() ? true : false;
    // }
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        string ans = "";

        // Brute Force | O (n ^ 3)
        // unordered_map<char, int> map;
        // for (char c: t) {
        //     map[c]++;
        // }
        // int n1 = t.size();
        // int minLenSub = INT_MAX;
        // int n = s.size();
        // for (int i = 0; i < n - n1 + 1; i++) {
        //     for (int j = i + n1 - 1; j < n; j++) {
        //     string str = s.substr(i, j - i + 1);
        //     int len = str.size();
        //         if (isValSub(str, map)) {
        //             if (minLenSub > len) {
        //                 ans = "";
        //                 ans += str;
        //                 minLenSub = len;
        //             }
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // Optimized 1 | Two Pointer | O(n^2)
        // unordered_map<char, int> map;
        // int n1 = t.size();
        // int minLenSub = INT_MAX;
        // int n = s.size();
        // for (int i = 0; i < n; i++) {
        //     for (char c: t) {
        //         map[c]++;
        //     }

        //     for (int j = i; j < n; j++) {
        //         if (map.count(s[j]) != 0) map[s[j]]--;
        //         if (map[s[j]] == 0) map.erase(s[j]);
        //         if (map.empty()) {
        //             string str = s.substr(i, j - i + 1);
        //             int len = str.size();                    
        //             if (minLenSub > len) {
        //                 ans = "";
        //                 ans += str;
        //                 minLenSub = len;
        //             }   
        //             break;
        //         }
        //     }
        //     map.clear();
        // }
        // return ans;

        // Optimized 2 | Sliding Window | O(n) 
        int map[128] = {0};
        for (char c: t) map[c]++;
        int n1 = t.size();
        int l = 0, r = 0, minLen = INT_MAX, sInd = -1, count = 0; 
        while (r < s.size()) {
            if (map[s[r]] > 0) count++;
            map[s[r]]--;
            while (count == n1) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sInd = l;
                }
                map[s[l]]++;
                if (map[s[l]] > 0) count--;
                l++;

            }
            r++;
        }
        return (sInd == -1) ? "" : s.substr(sInd, minLen);
    }

int main() {
    
    string s = "ADOBECODEBANC", t = "ABC";
    cout << minWindow(s, t) << endl;

    return 0;
}