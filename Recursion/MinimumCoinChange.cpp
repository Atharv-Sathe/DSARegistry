#include <vector>
#include <iostream>
using namespace std;

/*
Given an array of coins[] of size n and a target value sum, where coins[i] 
represent the coins of different denominations. You have an infinite supply 
of each of the coins. The task is to find the minimum number of coins required 
to make the given value sum. If it’s not possible to make a change, return -1.
*/

int minCoinsReq(int i, int sum, vector<int>& coins) {
  if (sum == 0) return 0;
  if (sum < 0 || i == coins.size()) return INT_MAX;

  int take = INT_MAX;
  if (coins[i] > 0) {
    take = minCoinsReq(i, sum - coins[i], coins);
    if (take != INT_MAX) take++;
  }

  int noTake = minCoinsReq(i + 1, sum , coins);
  return min(take, noTake);
}

int minCoins(vector<int> &coins, int sum) {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  int ans = minCoinsReq(0, sum, coins);
  return ans != INT_MAX ? ans : -1;
}

int main() {
  vector<int> coins = {25, 10, 5};
  int target = 30;
  cout << minCoins(coins, target);
  return 0;
}
