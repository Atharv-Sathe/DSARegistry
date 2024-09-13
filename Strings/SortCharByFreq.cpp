#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    // Approach 1
    // unordered_map<char, int> freq;
    // for (char &c: s) {
    //     freq[c]++;
    // }

    // vector<pair<char, int>> freqVect(freq.begin(), freq.end());
    // sort(freqVect.begin(), freqVect.end(), [](const auto &a, const auto &b) {
    //     return a.second > b.second;
    // });

    // string ans = "";

    // for (const auto &p: freqVect) {
    //     ans += string(p.second, p.first);
    // }
    // return ans;

    // Approach 2 
    unordered_map<char, int> freq;
    for (char &c: s) {
        freq[c]++;
    }

    priority_queue<pair<int, char>> freqQ;
    for (const auto &p: freq) {
        freqQ.push({p.second, p.first});
    }

    string ans;
    while(!freqQ.empty()) {
        auto [val, c] = freqQ.top();
        freqQ.pop();
        ans.append(val, c);
    }   
    return ans;
}


int main() {
    string s;
    s = "tree";

    cout << frequencySort(s) << endl;
    return 0;
}