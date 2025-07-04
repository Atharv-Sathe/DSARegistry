#include <bits/stdc++.h>
using namespace std;

/* You are a hiker preparing for an upcoming hike. You are given heights, a 2D
 array of size rows x columns, where heights[row][col] represents the height of
 cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to
 travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can
 move up, down, left, or right, and you wish to find a route that requires the
 minimum effort.

 A route's effort is the maximum absolute difference in heights between two
 consecutive cells of the route.

 Return the minimum effort required to travel from the top-left cell to the
 bottom-right cell.
*/

int minimumEffortPath(vector<vector<int>>& heights) {
  int m = heights.size();
  int n = heights[0].size();

  vector<vector<int>> effort(m, vector<int>(n, INT_MAX));
  effort[0][0] = 0;
  // PQ (min-heap) {effort, row, col}
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
  pq.push({0, 0, 0});

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  while (!pq.empty()) {
    int curEffort = pq.top()[0];
    int row = pq.top()[1];
    int col = pq.top()[2];
    pq.pop();

    if (row == m - 1 && col == n - 1) return curEffort;

    // If you have found a better path already continue
    if (curEffort > effort[row][col]) continue;

    for (int i = 0; i < 4; i++) {
      int newR = row + dx[i];
      int newC = col + dy[i];

      if (newR >= m || newC >= n || newR < 0 || newC < 0) continue;

      int newEffort =
          max(curEffort, abs(heights[newR][newC] - heights[row][col]));

      if (newEffort < effort[newR][newC]) {
        effort[newR][newC] = newEffort;
        pq.push({newEffort, newR, newC});
      }
    }
  }
  return effort[m - 1][n - 1];
}

int main() { return 0; }