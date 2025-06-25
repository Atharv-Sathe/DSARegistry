#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
  You are given an m x n grid where each cell can have one of three values:

  0 representing an empty cell,
  1 representing a fresh orange, or
  2 representing a rotten orange.
  Every minute, any fresh orange that is 4-directionally adjacent to a rotten 
  orange becomes rotten.

  Return the minimum number of minutes that must elapse until no cell has a fresh 
  orange. If this is impossible, return -1.
*/

int orangesRotting(vector<vector<int>>& grid) {
  int m = grid.size();
  int n = grid[0].size();

  int time{0};
  int freshCount{0};
  queue<pair<int, int>> queue;

  // Push all the rotten oranges into queue
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 2) {
        queue.push({i, j});
      } else if (grid[i][j] == 1) {
        freshCount++;
      }
    }
  }

  vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  while (!queue.empty()) {
    int curSize = queue.size();

    for (int i = 0; i < curSize; i++) {
      auto [r, c] = queue.front();
      queue.pop();
      for (auto& [x, y] : directions) {
        int newR = r + x;
        int newC = c + y;

        if (newR < 0 || newR >= m || newC < 0 || newC >= n) continue;

        if (grid[newR][newC] == 1) {
          queue.push({newR, newC});
          grid[newR][newC] = 2;
          freshCount--;
        }
      }
    }
    if (!queue.empty()) time++;
  }

  return (freshCount == 0) ? time : -1;
}

int main() { return 0; }