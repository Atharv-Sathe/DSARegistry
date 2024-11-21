#include <bits/stdc++.h>
using namespace std;

vector<string> genParRec(int n, vector<string>& pat) {
    if (n == 1) {
        pat.push_back("()");
        return pat;
    }

    pat = genParRec(n - 1, pat);
    vector<string> patNew;
    int i;
    // This solution is correct but since the order matters here, we need to update a little
    for (i = 0; i < pat.size(); i++) {
        patNew.push_back("(" + pat[i] + ")");
        patNew.push_back(pat[i] + "()");
        if (i != pat.size() - 1) patNew.push_back("()" + pat[i]);
    }
    return patNew;

}

void backtrack(vector<string>& res, string current, int open, int close, int max) {
    if (current.length() == 2 * max) {
        res.push_back(current);
        return;
    }

    if (open < max) {
        backtrack(res, current + "(", open + 1, close, max);
    }

    if (close < open) {
        backtrack(res, current + ")", open, close + 1, max);
    }
}

vector<string> generateParenthesis(int n) {
    // vector<string> pat;
    // return genParRec(n, pat);    

    vector<string> res;
    backtrack(res, "", 0, 0, n);
    return res;
}
int main() {
    
    return 0;
}
