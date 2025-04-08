#include <iostream>
#include <vector>
using namespace std;

    // TC : O(k ^ n)
    // SC : O (n) + O(n)
    int recurseTopDown(vector<int>& dp, vector<int>& arr, int k, int stone) {
      if (dp[stone] != -1) return dp[stone];
      int n = arr.size();
      if (stone == n - 1) return 0;
      
      int cost = INT_MAX;
      for (int i = stone + 1; i <= stone + k; i++) {
          if (n - 1 >= i) {
              int jumpCost = abs(arr[i] - arr[stone]);
              cost = min(cost, jumpCost + recurseTopDown(dp, arr, k, i));
          } else break;
      }
      
      dp[stone] = cost;
      return cost;
  }
  
  // TC : O(n*K)
  // SC : O(n)
  int recurseBottomUp(vector<int>& arr, int k) {
      vector<int> dp(10001, -1);
      int n = arr.size();
      
      dp[n - 1] = 0;
      for(int i = n - 2; i >= 0; i--) {
          int cost = INT_MAX;
          for (int j = i + 1; j <= i + k; j++) {
              if (n - 1 >= j) {
                  int jumpCost = abs(arr[j] - arr[i]);
                  cost = min(cost, jumpCost + dp[j]);
              } else break;
          }
          dp[i] = cost;
      }
      return dp[0];
  }

int main() {
  
  return 0;
}