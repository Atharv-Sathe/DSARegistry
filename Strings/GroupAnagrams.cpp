#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    // Brute Force | O(n^2 log n)
    // vector<vector<string>> ans;
    // vector<string> temp;
    // vector<string> strsCopy = strs;
    // for (string &str : strsCopy) {
    //     sort(str.begin(), str.end());
    // }
    // int i = 0;
    // int n = strs.size();
    // unordered_map<string, int> map;
    // while (i < n) {
    //     if (map.count(strsCopy[i]) == 0) {
    //         temp.push_back(strs[i]);
    //         map[strsCopy[i]]++;
    //         for (int j = i + 1; j < n; j++) {
    //             if (strsCopy[j] == strsCopy[i]) {
    //                 temp.push_back(strs[j]);
    //             }
    //         }
    //         ans.push_back(temp);
    //         temp.clear();
    //     } 
    //     i++;
    // }
    // return ans;

    // Optimization 1 | O (n^2)
    unordered_map<string, vector<string>> map;
    vector<vector<string>> ans;
    for (string &str: strs) {
        char charCount[26] = {0};
        for (char &c: str) {
            charCount[c - 'a']++;
        }
        string key = "";
        // Converting charCount array into a unique string
        for (char &a: charCount) {
            if (a != '0') key += a;
        }
        map[key].push_back(str);
    }

    for (auto &i: map) {
        ans.push_back(i.second);
    }
    return ans;
}


int main() {
    
    vector<string> strs; 
    strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto i: ans) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}