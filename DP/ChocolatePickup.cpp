#include <iostream>
#include <vector>
using namespace std;

/*
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. 
Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as 
possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right 
place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to 
the cells just below them. When anyone passes from any cell, he will pick all chocolates 
in it, and then the number of chocolates in that cell will become zero. If both stay in 
the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or 
(i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the 
help of his friends by following the above rules.
*/

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

int tabulation(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<vector<int>>> tab(m, vector<vector<int>>(n, vector<int>(n, -1)));

  for (int al = 0; al < n; al++) {
      for (int bob = 0; bob < n; bob++) {
          if (al == bob) tab[m - 1][al][bob] = grid[m - 1][al];
          else tab[m - 1][al][bob] = grid[m - 1][al] + grid[m - 1][bob];
      }
  }

  for (int row = m - 2; row >= 0; row--) {
      for (int alC = 0; alC <= n - 1; alC++) {
          for (int bobC = 0; bobC <= n - 1; bobC++) {
              int maxSum = INT_MIN;
              for (int i = -1; i <= 1; i++) {
                  for (int j = -1; j <= 1; j++) {
                      int j1 = alC + i, j2 = bobC + j;
                      if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
                          continue;
                      }
                      if (alC == bobC) {
                          maxSum = max(maxSum, grid[row][alC] + tab[row + 1][alC + i][bobC + j]);
                      } else {
                          maxSum = max(maxSum, grid[row][alC] + grid[row][bobC] + tab[row + 1][alC + i][bobC + j]);
                      }
                  }
              }
              tab[row][alC][bobC] = maxSum;
          }
      }
  }

  return tab[0][0][n - 1];
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