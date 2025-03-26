#include <iostream>
#include <vector>
using namespace std;

/*
  You are given an integer array nums. You are initially positioned at the 
  array's first index, and each element in the array represents your maximum 
  jump length at that position.

  Return true if you can reach the last index, or false otherwise.
*/

bool backtrack(vector<int>& nums, int curI) {
  if (curI == nums.size() - 1) return true;

  if (!nums[curI]) return false;

  for (int i = 1; i <= nums[curI]; i++) {
      if (backtrack(nums, curI + i)) return true;    
  }
  return false;
}

bool greedy(vector<int>& nums) {
  int goal = nums.size() - 1;
  for (int i = goal - 1; i >= 0; i--) {
      if (nums[i] >= goal - i) goal = i;
  }
  return (!goal) ? true : false;
}

bool canJump(vector<int>& nums) {
  // Brute Force
  // return backtrack(nums, 0);

  // Greedy 
  return greedy(nums);
}


int main() {
  
  return 0;
}