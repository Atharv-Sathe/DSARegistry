#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/dp/tasks/dp_h
*/

const int mod = 1e9 + 7;

int dx[2]{0, 1};
int dy[2]{1, 0};

int dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& dp) {
  int m = grid.size();
  int n = grid[0].size();
  if (i == m - 1 && j == n - 1) return 1;
  if (dp[i][j] != -1) return dp[i][j];
  int ways = 0;
  for (int k = 0; k < 2; k++) {
    int newR = i + dx[k];
    int newC = j + dy[k];

    if (newR < 0 || newR >= m || newC < 0 || newC >= n || grid[newR][newC] == '#') continue;

    ways += (dfs(grid, newR, newC, dp) % mod);
  }
  return dp[i][j] = (ways % mod);
}

int countPaths(vector<vector<char>>& grid, int h, int w) {
  vector<vector<int>> dp(h, vector<int>(w, -1));
  return dfs(grid, 0, 0, dp);
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w, '.'));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }

  cout << countPaths(grid, h, w);
  return 0;
}