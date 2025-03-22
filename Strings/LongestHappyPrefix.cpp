#include <iostream>
using namespace std;

/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix 
(excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" 
if no such prefix exists.
*/

string longestPrefix(string s) {
  long long prefix = 0, suffix = 0, base = 29, mod = 1000000007, power = 1;
  int lastMatchingInd = -1;
  // Remember the entire string as a prefix will always be its own suffix.
  // Hence we will be running the loop only till s.size() - 1 
  for (int i = 0; i < s.size() - 1; i++) {
      prefix = (prefix * base + s[i]) % mod;
      suffix = (suffix + power * s[s.size() - i - 1]) % mod;
      power = (power * base) % mod;

      if (suffix == prefix) lastMatchingInd = i;
  }

  return (lastMatchingInd == -1) ? "" : s.substr(0, lastMatchingInd + 1);
}

int main() {
  
  return 0;
}