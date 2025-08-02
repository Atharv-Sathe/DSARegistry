#include <bits/stdc++.h>
using namespace std;

// Taro : 0,  Jiro : 1

long long getScoreDiff(vector<int>& seq, int strt, int end, bool isJiro, vector<vector<vector<long long>>> dp) {
  if (strt > end) {
    return 1ll * 0;
  }
  if (dp[strt][end][isJiro] != -1) return dp[strt][end][isJiro];

  // Taro's Turn
  if (!isJiro) {
    long long takeStart = 1ll * seq[strt] + getScoreDiff(seq, strt + 1, end, true, dp);
    long long takeEnd = 1ll * seq[end] + getScoreDiff(seq, strt, end - 1, true, dp);
    return dp[strt][end][isJiro] = max(takeStart, takeEnd);
  }

  // Jiro's Turn
  long long takeStart = -1ll * seq[strt] + getScoreDiff(seq, strt + 1, end, false, dp);
  long long takeEnd = -1ll * seq[end] + getScoreDiff(seq, strt, end - 1, false, dp);
  return dp[strt][end][isJiro] = min(takeStart, takeEnd);
}

long long solveTab(vector<int>& seq) {
  int n = seq.size();
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n, vector<long long>(2, 0)));

  for (int start = n - 1; start >= 0; start--) {
    for (int end = start; end < n; end++) {
      for (int turn = 0; turn <= 1; turn++) {
        long long fact = (turn) ? -1ll : 1ll;
        if (end == start) {
          dp[start][end][turn] = fact * seq[start];
          continue;
        }
        long long takeStart = fact * seq[start] + dp[start + 1][end][!turn];
        long long takeEnd = fact * seq[end] + dp[start][end - 1][!turn];
        if (!turn) {
          dp[start][end][turn] = max(takeEnd, takeStart);
        } else {
          dp[start][end][turn] = min(takeEnd, takeStart);
        }
      }
    }
  }   

  return dp[0][n - 1][0];
}


long long solve(vector<int>& seq) {
  // int n = seq.size();
  // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
  // return getScoreDiff(seq, 0, n - 1, false, dp);

  return solveTab(seq);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> seq(n);
  for (int i = 0; i < n; i++) cin >> seq[i];
  cout << solve(seq);
  return 0;
}