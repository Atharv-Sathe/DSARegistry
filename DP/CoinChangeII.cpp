#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that 
amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
*/

// Memoization
int getNumberOfComb(vector<int> &coins, int amount, int ind, vector<vector<int>> &dp)
{
  if (ind == coins.size() && amount != 0)
    return 0;
  if (amount == 0)
    return 1;
  if (amount < 0)
    return 0;
  if (dp[ind][amount] != -1)
    return dp[ind][amount];

  int ways = 0;
  // take the current coin and want to reuse it
  ways += getNumberOfComb(coins, amount - coins[ind], ind, dp);

  // don't take the current coin
  ways += getNumberOfComb(coins, amount, ind + 1, dp);

  return dp[ind][amount] = ways;
}

// Tabulation
int getNumberOfCombTab(vector<int> &coins, int amount)
{
  vector<double> dp(amount + 1, 0);
  dp[0] = 1;

  for (int coin : coins)
    for (int amt = coin; amt <= amount; amt++)
      dp[amt] += dp[amt - coin];

  return (int)dp[amount];
}

int change(int amount, vector<int> &coins)
{
  // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
  // return getNumberOfComb(coins, amount, 0, dp);

  return getNumberOfCombTab(coins, amount);
}

int main()
{

  return 0;
}