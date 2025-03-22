#include <iostream>
using namespace std;

bool isPalindrome(string s) {
  int i = 0, j = s.length() - 1;
  while(i < j) {
      if (s[i] != s[j]) return false;
      i++;
      j--;
  }
  return true;
}

string rabinKarp(string& s) {
  if (s == "") return s;
  long long prefix = 0, suffix = 0, power = 1, base = 29, lastInd = 0, mod = 1000000007;

  for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      prefix = (1LL * prefix * base + c) % mod;
      suffix = (suffix + c * power * 1LL) % mod;
      if (i < s.size() - 1) power = (power * base) % mod;

      if (suffix == prefix) lastInd = i;
  }
  string revPart = "";
  if (lastInd < s.size() - 1) {
      revPart = s.substr(lastInd + 1);
      reverse(begin(revPart), end(revPart));
  }
  return revPart + s;
}


string shortestPalindrome(string s) {
  // // Brute Force
  // if (isPalindrome(s)) return s;
  // int n = s.size();
  // vector<bool> pal(n, false);
  // for (int i = 0; i < s.size(); i++) {
  //     string curStr = s.substr(0, i + 1);
  //     if (isPalindrome(curStr)) pal[i] = true;
  // }

  // int lastPalInd = -1;
  // for (int i = 0; i < s.size(); i++) if (pal[i]) lastPalInd = i;
  // string toReverse = s.substr(lastPalInd + 1, s.size() - lastPalInd - 1);
  // reverse(toReverse.begin(), toReverse.end());
  // string shortestPalindrome = toReverse + s;
  // return shortestPalindrome;

  return rabinKarp(s);
}

int main() {
  
  return 0;
}