#include <iostream>
#include <vector>
using namespace std;

/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a 
number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a 
balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
*/

// The intuition is to consider the last balloon that we might burst in an interval i - j
// and not the first, this is because considering first raises questions about how indices 
// will change after it bursts...

int memo(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
  if (i + 1 == j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  // Let k be the last balloon that we burst in the interval i - j
  int maxCoins = INT_MIN;
  for (int k = i + 1; k < j; k++)
  {
    maxCoins = max(maxCoins, nums[i] * nums[k] * nums[j] + memo(nums, i, k, dp) + memo(nums, k, j, dp));
  }
  return dp[i][j] = maxCoins;
}

int tab(vector<int> &nums)
{
  int n = nums.size();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int len = 2; len < n; len++)
  {
    for (int i = 0; i < n - len; i++)
    {
      int j = i + len;
      // Let k be the last balloon that we burst in the interval i - j
      int maxCoins = INT_MIN;
      for (int k = i + 1; k < j; k++)
      {
        maxCoins = max(maxCoins, nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
      }
      dp[i][j] = maxCoins;
    }
  }

  return dp[0][n - 1];
}

int maxCoins(vector<int> &nums)
{
  nums.insert(nums.begin(), 1);
  nums.push_back(1);
  // int n = nums.size();
  // vector<vector<int>> dp(n, vector<int>(n, -1));
  // return memo(nums, 0, n - 1, dp);

  return tab(nums);
}

int main()
{

  return 0;
}