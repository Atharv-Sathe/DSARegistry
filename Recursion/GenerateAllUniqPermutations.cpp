#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

void genPerm(int n, string& curr, unordered_map<char, int>& cnt, vector<string>& result) {
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }        
    
    for (const auto& p: cnt) {
        if (!p.second) continue;
        
        curr += p.first;
        cnt[p.first]--;
        genPerm(n, curr, cnt, result);
        cnt[p.first]++;
        curr.pop_back();
    }
}

vector<string> findPermutation(string &s) {
    string curr = "";
    vector<string> result;
    unordered_map<char, int> freq;
    for (char c: s) {
        freq[c]++;
    }
    genPerm(s.length(), curr, freq, result);
    return result;
}

int main() {
    
    return 0;
}