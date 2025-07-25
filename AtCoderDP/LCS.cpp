#include <bits/stdc++.h>
using namespace std;

/*
  https://atcoder.jp/contests/dp/tasks/dp_f
*/

int getLgstCmnSubseqLen(string& s, int i, string& t, int j,
                        vector<vector<int>>& dp) {
  if (i >= s.size() || j >= t.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (s[i] == t[j]) {
    return dp[i][j] = 1 + getLgstCmnSubseqLen(s, i + 1, t, j + 1, dp);
  }

  return dp[i][j] = max(getLgstCmnSubseqLen(s, i + 1, t, j, dp),
                        getLgstCmnSubseqLen(s, i, t, j + 1, dp));
}

string reconstruct(string& s, string& t, vector<vector<int>>& dp) {
  string result = "";
  int i = 0, j = 0;
  while(i < s.size() && j < t.size()) {
    if (s[i] == t[j]) {
      result += s[i];
      i++;
      j++;
    }
    else {
      // cout << dp[i + 1][j] << " " << dp[i][j + 1] << endl;
      if (dp[i + 1][j] > dp[i][j + 1]) i++;
      else j++;
    }
  }
  return result;
}

string tabulation(string& s, string& t) {
  int sLen = s.size(), tLen = t.size();
  vector<vector<int>> dp(sLen + 1, vector<int>(tLen + 1, 0));

  for (int i = sLen - 1; i >= 0; i--) {
    for (int j = tLen - 1; j >= 0; j--) {
      if (s[i] == t[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      }

      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }

  return reconstruct(s, t, dp);
}

int main() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
  // int len = getLgstCmnSubseqLen(s, 0, t, 0, dp);
  // cout << reconstruct(s, t, dp);

  cout << tabulation(s, t);

  return 0;
}