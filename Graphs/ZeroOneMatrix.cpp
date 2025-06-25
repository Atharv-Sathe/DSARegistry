#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  // Multi - Source BFS
  int m = mat.size();
  int n = mat[0].size();

  vector<pair<int, int>> dirc{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
  queue<pair<pair<int, int>, int>> q;

  vector<vector<int>> result(m, vector<int>(n, INT_MAX));
  // Add all the 0's to queue
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] == 0) {
        q.push({{i, j}, 0});
        result[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto [inner, d] = q.front();
    auto [r, c] = inner;
    q.pop();

    for (auto [x, y] : dirc) {
      int newR = r + x;
      int newC = c + y;

      if (newR >= m || newR < 0 || newC >= n || newC < 0) continue;

      if (mat[newR][newC] == 1 && result[newR][newC] > d + 1) {
        result[newR][newC] = d + 1;
        q.push({{newR, newC}, d + 1});
      }
    }
  }

  return result;
}

int main() { return 0; }