#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

*/

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  if (nums.size() < 4) return {};
  sort(begin(nums), end(nums));
  vector<vector<int>> result;
  for (int l = 0; l < nums.size() - 3; l++) {
      if (l > 0 && nums[l] == nums[l - 1]) continue;

      for (int j = l + 1; j < nums.size() - 2; j++) {
          if (j > l + 1 && nums[j] == nums[j - 1]) continue;

          int left = j + 1, right = nums.size() - 1;
          while(left < right) {
              long long sum = (long long)nums[l] + nums[j] + nums[left] + nums[right];
              if (sum < target) left++;
              else if (sum > target) right--;
              else {
                  result.push_back({nums[l], nums[j], nums[left], nums[right]});

                  while(left < right && nums[left] == nums[left + 1]) left++;
                  while(left < right && nums[right] == nums[right - 1]) right--;
                  left++;
                  right--;
              }   
          }
      }
  }
  return result;
}

int main() {
  
  return 0;
}