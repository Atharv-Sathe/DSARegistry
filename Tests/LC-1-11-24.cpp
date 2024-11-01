#include <bits/stdc++.h>
using namespace std;

string makeFancyString(string s) {
    int conseqCharCount = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == s[i]) conseqCharCount++;
        else conseqCharCount = 1;
        if (conseqCharCount == 3) {
            s.erase(s.begin() + i);
            i--;
            conseqCharCount--;
        }
    }
    return s;
}


int main() {

    string str = "aaabaaaa";
    cout << makeFancyString(str) << endl;    

    return 0;
}