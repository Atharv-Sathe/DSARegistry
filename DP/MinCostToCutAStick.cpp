#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given a wooden stick of length n units. The stick is labelled from 0 to n. 
For example, a stick of length 6 is labelled as follows:


Given an integer array cuts where cuts[i] denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the 
sum of costs of all cuts. When you cut a stick, it will be split into two smaller 
sticks (i.e. the sum of their lengths is the length of the stick before the cut). 
Please refer to the first example for a better explanation.

Return the minimum total cost of the cuts.
*/

int getMinCostMemo(vector<int> &cuts, int i, int j, vector<vector<int>> &dp)
{
  if (i + 1 == j)
    return 0; // No cuts between adjacent positions
  if (dp[i][j] != -1)
    return dp[i][j];

  int minCost = INT_MAX;
  for (int k = i + 1; k < j; k++)
  {
    minCost = min(minCost, j - i + getMinCostMemo(cuts, i, k, dp) + getMinCostMemo(cuts, k, j, dp));
  }

  return dp[i][j] = minCost;
}

int minCost(int n, vector<int> &cuts)
{
  // unordered_set<int> used;
  // return getMinCost(cuts, used, 0, n);
  cuts.push_back(0), cuts.push_back(n);
  sort(cuts.begin(), cuts.end());
  int len = cuts.size();
  vector<vector<int>> dp(len, vector<int>(len, -1));
  return getMinCostMemo(cuts, 0, len - 1, dp);
}

int main()
{

  return 0;
}