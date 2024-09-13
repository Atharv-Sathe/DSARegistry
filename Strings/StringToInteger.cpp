#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    bool isNeg = false;
    int ind = 0;
    int n = s.size();

    // To skip leading whitespaces
    while (ind < n && s[ind] == ' ') {
        ind++;
    }
    if (ind == n) return 0;

    // To detect signs
    if (s[ind] == '-' || s[ind] == '+') {
        isNeg = (s[ind] == '-') ? true : false;
        ind++;
    }

    int ans = 0;
    while ((s[ind] >= '0' && s[ind] <= '9') && ind < n) {
        int digit = s[ind] - '0';
        if (ans > (INT_MAX - digit) / 10) return (isNeg) ? INT_MIN : INT_MAX;
        ans = ans * 10 + digit;
        ind++;
    }

    return (isNeg) ? -ans : ans;
}

int main() {
    string s;
    s = "+-12";

    cout << myAtoi(s) << endl;
    return 0;
}