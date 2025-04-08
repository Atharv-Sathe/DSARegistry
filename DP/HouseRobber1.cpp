#include <iostream>
#include <vector>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house 
has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security systems connected and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return 
the maximum amount of money you can rob tonight without alerting the police.
*/


int naiveRecurse(vector<int>& nums, int i) {
  if (i < 0) return 0;
  return max(naiveRecurse(nums, i - 2) + nums[i], naiveRecurse(nums, i - 1));
}

int dpRecurse(vector<int>& dp, vector<int>& nums, int i) {
  if (i < 0) return 0;
  if (dp[i] != -1) return dp[i];

  int robCurCost = nums[i] + dpRecurse(dp, nums, i - 2);
  int noRobCurCost = dpRecurse(dp, nums, i - 1);

  dp[i] = max(robCurCost, noRobCurCost);
  return dp[i];
}

int dpIterBottomUp(vector<int>& nums) {
  vector<int> dp(101, -1);
  if (nums.size() < 2) return nums[0];

  // if a house is at index i in nums, then the max cost or starting looting 
  // from there is stored at dp[i + 1], this is done for cases like where 
  // nums.size() = 2
  dp[0] = 0;
  dp[1] = nums[0];
  for (int i = 1; i < nums.size(); i++) {
      int robCurCost = nums[i] + dp[i - 1];
      int skipCurCost = dp[i];
      dp[i + 1] = max(robCurCost, skipCurCost);
  }
  return dp[nums.size()];
}

int main() {
  
  return 0;
}