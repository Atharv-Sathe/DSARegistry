#include <iostream>
#include <vector>
using namespace std;

int recurseNaive(vector<vector<int>>& grid, int row, int alC, int bobC) {
  int m = grid.size(), n = grid[0].size();
  if (bobC >= n || bobC < 0 || alC >= n || alC < 0) {
      return -1e8;
  } 

  if (row == m - 1) {
      if (alC == bobC) return grid[row][bobC];
      else return grid[row][bobC] + grid[row][alC];
  }

  // For every move of alice bob has three moves
  int maxSum = INT_MIN;
  for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
          if (alC == bobC) {
              maxSum = max(maxSum, grid[row][alC] + recurseNaive(grid, row + 1, alC + i, bobC + j));
          } else {
              maxSum = max(maxSum, grid[row][alC] + grid[row][bobC] + recurseNaive(grid, row + 1, alC + i, bobC + j));
          }
      }
  }
  return maxSum;
}

int memoization(vector<vector<int>>& grid, vector<vector<vector<int>>>& memo, int row, int alC, int bobC) {
  int m = grid.size(), n = grid[0].size();
  if (bobC >= n || bobC < 0 || alC >= n || alC < 0) {
      return -1e8;
  } 

  if (memo[row][alC][bobC] != -1) return memo[row][alC][bobC];

  if (row == m - 1) {
      if (alC == bobC) return grid[row][bobC];
      else return grid[row][bobC] + grid[row][alC];
  }

  // For every move of alice bob has three moves
  int maxSum = INT_MIN;
  for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
          if (alC == bobC) {
              maxSum = max(maxSum, grid[row][alC] + memoization(grid, memo, row + 1, alC + i, bobC + j));
          } else {
              maxSum = max(maxSum, grid[row][alC] + grid[row][bobC] + memoization(grid, memo, row + 1, alC + i, bobC + j));
          }
      }
  }
  memo[row][alC][bobC] = maxSum;
  return maxSum;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));
  // return recurseNaive(grid, 0, 0, n - 1);
  return memoization(grid, memo, 0, 0, n - 1);
}

int main() {
  
  return 0;
}