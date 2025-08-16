#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int solve(vector<vector<int>>& grid, int i, int mask, vector<vector<int>>& dp) {
  int n = grid.size();
  if (i == n) return mask == 0 ? 1 : 0;
  if (dp[i][mask] != -1) return dp[i][mask];
  long long ways = 0;
  for (int j = 0; j < n; j++) {
    if (grid[i][j] &&  mask & (1 << j)) {
      ways += solve(grid, i + 1, mask & ~(1 << j), dp); 
    }
  }
  return dp[i][mask] = ways % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];

  int mask = (1 << n) - 1;
  vector<vector<int>> dp(n, vector<int>(mask + 1, -1));
  cout << solve(grid, 0, mask, dp);

  return 0;
}
