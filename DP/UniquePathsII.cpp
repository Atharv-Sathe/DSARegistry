#include <iostream>
#include <vector>
using namespace std;

/*
You are given an m x n integer array grid. There is a robot initially located at 
the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right 
corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at 
any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the 
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the 
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

*/


int recurseDPBottomUp(vector<vector<int>>& obstacleGrid, vector<vector<int>>& memo, int r, int c) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  if (r == m - 1 && c == n - 1) return 1;
  if (r >= m || c >= n || obstacleGrid[r][c]) return 0;
  if (memo[r][c] != -1) return memo[r][c];

  int result = recurseDPBottomUp(obstacleGrid, memo, r + 1, c) + recurseDPBottomUp(obstacleGrid, memo, r, c + 1);
  memo[r][c] = result;

  return result;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size(), n = obstacleGrid[0].size();
  if (obstacleGrid[m - 1][n - 1]) return 0;
  vector<vector<int>> memo(m, vector<int>(n, -1));
  return recurseDPBottomUp(obstacleGrid, memo, 0, 0);
}

int main() {
  
  return 0;
}