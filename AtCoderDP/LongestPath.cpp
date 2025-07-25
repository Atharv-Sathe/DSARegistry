#include <bits/stdc++.h>
using namespace std;

/*
  https://atcoder.jp/contests/dp/tasks/dp_g
*/

int dfs(vector<vector<int>>& adjList, int i, vector<int>& dp) {
  if (dp[i] != -1) return dp[i];
  int maxPathLen = 0;
  for (int nbr: adjList[i]) {
    int len = 1 + dfs(adjList, nbr, dp);
    maxPathLen = max(maxPathLen, len);
  }
  return dp[i] = maxPathLen;
}

int solve(vector<vector<int>>& adjList) {
  int n = adjList.size();
  vector<int> dp(n, -1);
  int maxPathLen = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == -1) {
      maxPathLen = max(maxPathLen, dfs(adjList, i, dp));
    }
  }
  return maxPathLen;
}

int main() {
  int n; int m;
  cin >> n >> m;
  vector<vector<int>> adjList(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adjList[x - 1].push_back(y - 1);
  }

  cout << solve(adjList);
  return 0;
}