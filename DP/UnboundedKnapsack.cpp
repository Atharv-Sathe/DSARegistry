#include <iostream>
#include <vector>
using namespace std;

/*
Given a set of items, each with a weight and a value, represented by the
array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit.
Return the maximum profit.
Note: Each item can be taken any number of times.
*/

int getMaxProfit(vector<int> &val, vector<int> &wt, int capacity, int ind, vector<vector<int>> &dp)
{
  if (capacity <= 0 || ind == wt.size())
    return 0;
  if (dp[ind][capacity] != -1)
    return dp[ind][capacity];

  int takeProf = (capacity - wt[ind] >= 0) ? val[ind] + getMaxProfit(val, wt, capacity - wt[ind], ind, dp) : 0;
  int noTakeProf = getMaxProfit(val, wt, capacity, ind + 1, dp);

  return dp[ind][capacity] = max(takeProf, noTakeProf);
}

int getMaxProfTab(vector<int> &val, vector<int> &wt, int capacity)
{
  vector<int> dp(capacity + 1, 0);
  for (int i = 0; i < val.size(); i++)
  {
    for (int cap = wt[i]; cap <= capacity; cap++)
    {
      dp[cap] = max(dp[cap], dp[cap - wt[i]] + val[i]);
    }
  }
  return dp[capacity];
}

int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
  // vector<vector<int>> dp(val.size(), vector<int>(capacity + 1, -1));
  // return getMaxProfit(val, wt, capacity, 0, dp);

  return getMaxProfTab(val, wt, capacity);
}

int main()
{

  return 0;
}