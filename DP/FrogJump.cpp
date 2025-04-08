#include <iostream>
#include <vector>
using namespace std;

    // TC : O(n)
    // SC : O(n) + O(n)
    int recurseTopDown(vector<int>& dp, vector<int>& height, int stair) {
      if (dp[stair] != -1) return dp[stair];
      int h = height.size();
      if (stair == h - 1) {
          return 0;
      } 
      
      int costi1 = INT_MAX, costi2 = INT_MAX;
      if (h - 1 >= stair + 1) {
          int i1Cost = abs(height[stair + 1] - height[stair]);
          costi1 = i1Cost + recurseTopDown(dp, height, stair + 1);
      }
      if (h - 1 >= stair + 2) {
          int i2Cost = abs(height[stair + 2] - height[stair]);
          costi2 = i2Cost + recurseTopDown(dp, height, stair + 2);
      }
      int cost = min(costi1, costi2);
      dp[stair] = cost;
      return cost;
  }
  
  // TC : O(n)
  // SC : O(n)
  int iterBottomUp(vector<int>& height) {
      vector<int> dp(100001, -1);
      int h = height.size();
      
      dp[h - 1] = 0;
      for (int i = h - 2; i >= 0; i--) {
          int costi1 = INT_MAX, costi2 = INT_MAX;
          if (h - 1 >= i + 1) {
              int oneJumpCost = abs(height[i + 1] - height[i]);
              costi1 = oneJumpCost + dp[i + 1];
          } 
          if (h - 1 >= i + 2) {
              int twoJumpCost = abs(height[i + 2] - height[i]);
              costi2 = twoJumpCost + dp[i + 2];
          }
          dp[i] = min(costi2, costi1);
      }   
      
      return dp[0];
  }
  
  // TC : O(n)
  // SC : O(1)
  int iterBottomUpSpaceOp(vector<int>& height) {
      int h = height.size();
      
      int next2 = 0, next1 = abs(height[h - 1] - height[h - 2]); 
      if (h <= 2) return (h == 2) ? next1 : next2;
      
      int current = 0;
      for (int i = h - 3; i >= 0; i--) {
          int costi1 = abs(height[i + 1] - height[i]) + next1;
          int costi2 = abs(height[i + 2] - height[i]) + next2;
          current = min(costi2, costi1);
          next2 = next1;
          next1 = current;
      }   
      
      return current;
  }

int main() {
  
  return 0;
}