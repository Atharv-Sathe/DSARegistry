#include <iostream>
#include <vector>
using namespace std;

/*
Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right, which minimizes the sum of all numbers along 
its path.

Note: You can only move either down or right at any point in time.
*/

// TC: O(2^(m + n)) SC: O(m * n)
int recurse(vector<vector<int>>& grid, int sum, int r, int c) {
  int m = grid.size(), n = grid[0].size();
  if (r == m - 1 && c == n - 1) return sum + grid[r][c];

  int minSum = INT_MAX;
  // Moving Down
  int newR = r + 1;
  if (newR < m) minSum = min(minSum, recurse(grid, sum + grid[r][c], newR, c));
  // Moving Right
  int newC = c + 1;
  if (newC < n) minSum = min(minSum, recurse(grid, sum + grid[r][c], r, newC));
  return minSum;
}

// TC: O(m * n) SC: O(m * n) + O(m * n)
int memoization(vector<vector<int>>& grid, vector<vector<int>>& memo, int r, int c) {
  int m = grid.size(), n = grid[0].size();
  if (r == m - 1 && c == n - 1) return grid[r][c];
  if (memo[r][c] != -1) return memo[r][c];

  // Moving Down
  int resDown = INT_MAX;
  if (r + 1 < m) resDown = grid[r][c] + memoization(grid, memo, r + 1, c);
  // Moving Right
  int resRight = INT_MAX;
  if (c + 1 < n) resRight = grid[r][c] + memoization(grid, memo, r, c + 1);

  memo[r][c] = min(resDown, resRight);
  return memo[r][c];
}


// TC : O(m * n) SC : O(m * n)
int tabulation(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> tab(m, vector<int>(n, INT_MAX));
  tab[m - 1][n - 1] = grid[m - 1][n - 1];
  for (int i = m - 1; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
          if (i == m - 1 && j == n - 1) continue;
          int down = (i + 1 < m) ? tab[i + 1][j] : INT_MAX;
          int right = (j + 1 < n) ? tab[i][j + 1] : INT_MAX;

          tab[i][j] = grid[i][j] + min(down, right);
      }
  }
  return tab[0][0];
}

// TC: O(m * n) SC: O(n)
int tabulationSpaceOp(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<int> tab(n, INT_MAX);
  tab[n - 1] = grid[m - 1][n - 1];
  int right;
  for (int i = m - 1; i >= 0; i--) {
      right = tab[n - 1];
      for (int j = n - 1; j >= 0; j--) {
          if (i == m - 1 && j == n - 1) continue;
          right = grid[i][j] + min(tab[j], right);
          tab[j] = right;
      }
  }
  return tab[0];
}

int minPathSum(vector<vector<int>>& grid) {
  // return recurse(grid, 0, 0, 0);
  // int m = grid.size(), n = grid[0].size();
  // vector<vector<int>> memo(m, vector<int>(n, -1));
  // return memoization(grid, memo, 0, 0);
  // return tabulation(grid);
  return tabulationSpaceOp(grid);
}

int main() {
  
  return 0;
}