#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/

// Memoization
int getLenLIS(vector<int> &nums, int i, int prev, vector<vector<int>> &dp)
{
  if (i == nums.size())
    return 0;
  if (dp[i][prev + 1] != -1)
    return dp[i][prev + 1];

  // no take
  int noTake = getLenLIS(nums, i + 1, prev, dp);

  // take if prev is smaller strictly
  int take = 0;
  if (prev == -1 || nums[prev] < nums[i])
  {
    take = 1 + getLenLIS(nums, i + 1, i, dp);
  }

  return dp[i][prev + 1] = max(take, noTake);
}

int getLgstLenLISTab(vector<int>& nums) {
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  // For j we are shifting the indices 1 towards right, so -1 is represented by 0 and so on
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= -1; j--) {
      // no take
      int noTake = dp[i + 1][j + 1];

      // take if prev is smaller strictly
      int take = 0;
      if (j == -1 || nums[j] < nums[i])
      {
        take = 1 + dp[i + 1][i + 1];
      }

      dp[i][j + 1] = max(take, noTake);
      
    }
  }

  return dp[0][0];
}

int getLgstLenLISTabSpaceOp(vector<int>& nums) {
  int n = nums.size();
  vector<int> curr(n + 1, 0), next(n + 1, 0);

  // For j we are shifting the indices 1 towards right, so -1 is represented by 0 and so on
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i - 1; j >= -1; j--) {
      // no take
      int noTake = next[j + 1];

      // take if prev is smaller strictly
      int take = 0;
      if (j == -1 || nums[j] < nums[i])
      {
        take = 1 + next[i + 1];
      }

      curr[j + 1] = max(take, noTake);
    }
    next = curr;
  }

  return curr[0];
}

// Sexy Tabulation
int sexyTab(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 1);

  // dp[i] represents the length of longest increasing subsequence ending at i
  int maxLen = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      // For every element i we are checking selecting or not selecting which previous
      // element j will give us the max output and we will store this
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    maxLen = max(maxLen, dp[i]);
  }

  return maxLen;
}

// Super Sexy using Bin Srch
int getLenLISBS(vector<int>& nums) {
  vector<int> tails;

  // tails[i] represents the smallest ending element amongst 
  // all the Increasing Subseq of length i + 1
  
  for (int i = 0; i < nums.size(); i++) {
    if (tails.empty() || tails.back() < nums[i]) {
      tails.push_back(nums[i]);
    } else {
      auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
      tails[it - tails.begin()] = nums[i];
    }
  }

  return tails.size();
}

int main()
{

  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
  cout << getLenLIS(nums, 0, -1, dp) << endl;
  cout << getLgstLenLISTab(nums) << endl;
  cout << getLgstLenLISTabSpaceOp(nums) << endl;
  cout << sexyTab(nums) << endl;
  cout << getLenLISBS(nums) << endl;

  return 0;
}