#include <iostream>
#include <vector>
using namespace std;

/*
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix 
has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices 
together. The efficient way is the one that involves the least number of multiplications.
*/

int getMinMatMul(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
  if (j == i + 1)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  int res = INT_MAX;
  for (int k = i + 1; k < j; k++)
  {
    int ways = getMinMatMul(arr, i, k, dp) + getMinMatMul(arr, k, j, dp) + (arr[i] * arr[k] * arr[j]);

    res = min(res, ways);
  }

  return dp[i][j] = res;
}

/*
When subproblems depend on smaller ranges, use length based iteration while converting from
memoization to tabulation, here in order to solve dp[i][j], dp[i][k] and dp[k][j] must be known
in advance, both of these are smaller ranges.
*/
int getMinMultTab(vector<int> &arr)
{
  int n = arr.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int len = 2; len < n; len++)
  {
    for (int i = 0; i < n - len; i++)
    {
      int j = i + len;
      dp[i][j] = INT_MAX;
      for (int k = i + 1; k < j; k++)
      {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j]));
      }
    }
  }

  return dp[0][n - 1];
}

int matrixMultiplication(vector<int> &arr)
{
  // int n = arr.size();
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // return getMinMatMul(arr, 0, arr.size() - 1, dp);

  return getMinMultTab(arr);
}

int main()
{

  return 0;
}