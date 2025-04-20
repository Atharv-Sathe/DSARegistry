#include <iostream>
#include <vector>
using namespace std;

/*
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

// Memoization
int getMinCoins(vector<int> &coins, int amount, vector<int> &dp)
{
  if (amount < 0)
    return 1e8;
  if (amount == 0)
    return 0;
  if (dp[amount] != -1)
    return dp[amount];

  int minCoins = 1e8;
  for (int i : coins)
  {
    minCoins = min(minCoins, 1 + getMinCoins(coins, amount - i, dp));
  }

  return dp[amount] = minCoins;
}

// Tabulation
inline int getMinCoinsTab(vector<int> &coins, int amount)
{
  vector<int> dp(amount + 1, 1e8);
  dp[0] = 0;

  for (int i = 1; i <= amount; i++)
  {
    int minCoins = 1e8;
    for (int coin : coins)
    {
      if (i - coin >= 0)
        minCoins = min(minCoins, 1 + dp[i - coin]);
    }
    dp[i] = minCoins;
  }
  return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
  vector<int> dp(amount + 1, -1);
  // int ans = getMinCoins(coins, amount, dp);
  // return (ans == 1e8) ? -1 : ans;
  int ans = getMinCoinsTab(coins, amount);
  return (ans == 1e8) ? -1 : ans;
}

int main()
{

  return 0;
}