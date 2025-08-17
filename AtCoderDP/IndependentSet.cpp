#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int memo(vector<vector<int>>& adjList, int v, bool canPaintBlack, int parent, vector<vector<int>>& dp) {
  if (dp[v][canPaintBlack] != -1) return dp[v][canPaintBlack];
  long long waysWhite = 1;
  long long waysBlack = 1;

  for (int nbr : adjList[v]) {
    if (nbr == parent) continue;

    // Current Vertex is white children can be both
    waysWhite = (waysWhite * memo(adjList, nbr, true, v, dp)) % MOD;

    // Current Vertex is black chidren must be white
    waysBlack = (waysBlack * memo(adjList, nbr, false, v, dp)) % MOD;
  }

  long long totalWays = waysWhite;
  if (canPaintBlack) totalWays = (totalWays + waysBlack) % MOD;

  return dp[v][canPaintBlack] = totalWays;
}

int solve(vector<pair<int, int>>& edges) {
  int nodeCount = edges.size() + 1;
  vector<vector<int>> adjList(nodeCount);
  for (const auto& edge : edges) {
    adjList[edge.first].push_back(edge.second);
    adjList[edge.second].push_back(edge.first);
  }
  vector<vector<int>> dp(nodeCount, vector<int>(2, -1));
  return memo(adjList, 0, true, -1, dp);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  vector<pair<int, int>> edges(n - 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    edges[i] = pair<int, int>({x - 1, y - 1});
  }
  cout << solve(edges);
  return 0;
}