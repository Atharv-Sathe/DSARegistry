#include <iostream>
#include <vector>
using namespace std;

/*
You are a professional robber planning to rob houses along a street. Each house has 
a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, adjacent houses 
have a security system connected, and it will automatically contact the police if two 
adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the 
maximum amount of money you can rob tonight without alerting the police.
*/

int dpRecurse(vector<int>& dp, vector<int>& nums, int i, int end) {
  if (i < end) return 0;
  if (dp[i] != -1) return dp[i];

  int robCurCost = nums[i] + dpRecurse(dp, nums, i - 2, end);
  int noRobCurCost = dpRecurse(dp, nums, i - 1, end);

  dp[i] = max(robCurCost, noRobCurCost);
  return dp[i];
}


int rob(vector<int>& nums) {
  int n = nums.size();
  if (n == 1) return nums[0];
  vector<int> dp1(101, -1);
  vector<int> dp2(101, -1);
  int res1 = dpRecurse(dp1, nums, n - 2, 0);
  int res2 = dpRecurse(dp2, nums, n - 1, 1);

  return max(res1, res2);
}


int main() {
  
  return 0;
}