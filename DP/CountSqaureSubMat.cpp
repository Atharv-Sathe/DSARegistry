#include <iostream>
#include <vector>
using namespace std;

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
*/

int getSquareCount(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp)
{
  // dp[i][j] represents the lgst sq sub mat ending at i, j or number of sq sub mat ending at i, j
  if (i < 0 || j < 0)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (matrix[i][j])
    return dp[i][j] = min(getSquareCount(matrix, i, j - 1, dp),
                          min(getSquareCount(matrix, i - 1, j, dp),
                              getSquareCount(matrix, i - 1, j - 1, dp))) +
                      1;
  // Current cell 0 means can't start a sq sub mat
  return dp[i][j] = 0;
}

int getSquareCountTab(vector<vector<int>> &matrix)
{
  int m = matrix.size(), n = matrix[0].size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  int sqCount = 0;
  for (int k = 1; k <= m; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      if (matrix[k - 1][i - 1])
        dp[k][i] = min(dp[k][i - 1], min(dp[k - 1][i], dp[k - 1][i - 1])) + 1;
      else
        dp[k][i] = 0;
      sqCount += dp[k][i];
    }
  }

  return sqCount;
}

int countSquares(vector<vector<int>> &matrix)
{
  // int m = matrix.size(), n = matrix[0].size();
  // vector<vector<int>> dp(m, vector<int>(n, -1));
  // getSquareCount(matrix, m - 1, n - 1, dp);
  // int sqCount = 0;
  // for (int i = 0; i < m; i++) {
  //     for (int j = 0; j < n; j++) {
  //         sqCount += getSquareCount(matrix, i, j, dp);
  //     }
  // }
  // return sqCount;

  return getSquareCountTab(matrix);
}

int main()
{

  return 0;
}