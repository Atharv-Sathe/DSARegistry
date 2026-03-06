#include<iostream>
using namespace std;

int solve(string s) {
  int lgstRepLen = 0;
  int curRepLen = 1;
  for (int i = 1; i < s.size(); i++) {
       if (s[i] == s[i - 1]) {
       curRepLen++;
       } else {
       lgstRepLen = max(lgstRepLen, curRepLen);
       curRepLen = 1;
       }
  }
  lgstRepLen = max(lgstRepLen, curRepLen);
  return lgstRepLen;
}

int main() {
  string s;
  cin >> s;
  cout << solve(s);
  return 0;
}
    
