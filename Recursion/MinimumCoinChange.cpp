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

int main() {
  vector<int> coins = {25, 10, 5};
  int target = 30;
  cout << minCoinsReq(0, target, coins);
  return 0;
}
