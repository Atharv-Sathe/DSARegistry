#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void solve(string s) {
  int charFreq[26] = {0};
  for (char c: s) {
    charFreq[c - 'A']++;
  }
  int n = s.size();
  string halfPal = "";
  int oddFreqCount = 0;
  int oddChar = -1;
  for (int i = 0; i < 26; i++) {
    if (charFreq[i] & 1) {
      oddFreqCount++;
      oddChar = i;
      if (oddFreqCount > 1) {
        cout << "NO SOLUTION";
        return;
      }
      charFreq[i]--;
    }
    for (int j = 0; j < charFreq[i] / 2; j++) {
      halfPal += ('A' + i);
    }
  }
  string halfPalTemp = halfPal; 
  reverse(halfPal.begin(), halfPal.end());
  if (oddChar != -1) halfPalTemp += ('A' + oddChar);
  cout << halfPalTemp << halfPal;
  return; 
}

int main() {
  string s;
  cin >> s;
  solve(s);
  return 0;
}


