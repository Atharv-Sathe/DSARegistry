#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array arr, partition the array into (contiguous)
subarrays of length at most k. After partitioning, each subarray has their
values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are
generated so that the answer fits in a 32-bit integer.
*/

int getMaxSum(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> dp(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    int maxElem = arr[i - 1];
    for (int j = 1; j <= k && i - j >= 0; j++)
    {
      maxElem = max(maxElem, arr[i - j]);
      dp[i] = max(dp[i], dp[i - j] + maxElem * j);
    }
  }

  return dp[n];
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
  return getMaxSum(arr, k);
}

int main()
{

  return 0;
}