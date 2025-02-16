#include <iostream>
#include <stack>
#include <string>
using namespace std;

string removeKdigits(string num, int k) {
    if (k >= num.size()) return "0";
    stack<char> s;
    string res = "";
    for (int i = 0; i < num.length(); i++) {
        while (k && !s.empty() && num[i] < s.top()) {
            s.pop();
            k--;
        }
        s.push(num[i]);

        // Pop preceeding zeros
        if (s.size() == 1 && num[i] == '0') {
            s.pop(); 
        }
    }
    while(k && !s.empty()) {
        // for cases like "456" where every num[i] > s.top()
        k--;
        s.pop();
    }

    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    
    if (!res.length()) return "0";
    return res;
}

int main() {
    
    return 0;
}