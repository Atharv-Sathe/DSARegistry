#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the
 symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and 
concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

// Memoization
int getTarSumWays(vector<int> &nums, int target, int i, vector<vector<int>> &dp)
{
  if (i == nums.size())
    return (target) ? 0 : 1;
  if (dp[i][target + 2000] != -1)
    return dp[i][target + 2000];
  // '+'
  int add = getTarSumWays(nums, target - nums[i], i + 1, dp);

  // '-'
  int sub = getTarSumWays(nums, target + nums[i], i + 1, dp);

  return dp[i][target + 2000] = add + sub;
}

// Tabulation
int getTarSumWaysTab(vector<int> &nums, int target)
{
  vector<vector<int>> dp(nums.size(), vector<int>(4001, 0));
  if (nums[0])
  {
    dp[0][2000 - nums[0]] = 1;
    dp[0][2000 + nums[0]] = 1;
  }
  else
  {
    dp[0][2000] = 2;
  }

  for (int i = 1; i < nums.size(); i++)
  {
    for (int target = -2000; target <= 2000; target++)
    {
      int tempInd = 2000 + target - nums[i];
      int add = (tempInd >= 0 && tempInd < 4001) ? dp[i - 1][tempInd] : 0;
      tempInd = 2000 + target + nums[i];
      int sub = (tempInd >= 0 && tempInd < 4001) ? dp[i - 1][tempInd] : 0;

      dp[i][2000 + target] = add + sub;
    }
  }

  return dp[nums.size() - 1][2000 + target];
}

// Clever Way Convert it into Subset Sum Problem
int subsetSum(vector<int> &nums, int target)
{
  int sum = accumulate(begin(nums), end(nums), 0);

  if (((sum + target) & 1) || abs(target) > sum)
    return 0;

  int P = (sum + target) / 2;

  vector<int> dp(P + 1, 0);
  dp[0] = 1;

  for (int num : nums)
  {
    for (int i = P; i >= num; i--)
    {
      dp[i] += dp[i - num];
    }
  }

  return dp[P];
}

int main()
{

  return 0;
}