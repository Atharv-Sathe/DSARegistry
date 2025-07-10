#include <bits/stdc++.h>
using namespace std;

/*
You are given an n x n integer matrix grid where each value 
grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere
is t. You can swim from a square to another 4-directionally adjacent square 
if and only if the elevation of both squares individually are at most t. 
You can swim infinite distances in zero time. Of course, you must stay within 
the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) 
if you start at the top left square (0, 0).

*/

bool doesPathExist(vector<vector<int>>& grid, int t) {
  if (grid[0][0] > t) return false;

  int n = grid.size();
  queue<vector<int>> q;
  q.push({0, 0});
  vector<bool> visited(n * n, false);
  visited[0] = true;

  int dx[]{0, 1, 0, -1};
  int dy[]{1, 0, -1, 0};

  while (!q.empty()) {
    int r = q.front()[0], c = q.front()[1];
    q.pop();

    if (r == n - 1 && c == n - 1) return true;

    for (int i = 0; i < 4; i++) {
      int newR = r + dx[i];
      int newC = c + dy[i];

      if (newR < 0 || newC < 0 || newR >= n || newC >= n ||
          visited[newR * n + newC])
        continue;

      if (grid[r][c] <= t && grid[newR][newC] <= t) {
        q.push({newR, newC});
        visited[newR * n + newC] = true;
      }
    }
  }
  return false;
}


// TC : (N^2 Log N)
int swimInWater(vector<vector<int>>& grid) {
  int gridMax = INT_MIN;
  int gridMin = INT_MAX;
  int n = grid.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      gridMax = max(gridMax, grid[i][j]);
      gridMin = min(gridMin, grid[i][j]);
    }
  }

  while (gridMin < gridMax) {
    int gridMid = gridMin + (gridMax - gridMin) / 2;
    if (doesPathExist(grid, gridMid))
      gridMax = gridMid;
    else
      gridMin = gridMid + 1;
  }

  return gridMin;
}

int main() { return 0; }