#include <iostream>
#include <vector>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.
*/

int getMinCut(string &s, int i, int j, vector<vector<int>> &dp, vector<vector<bool>> &pal)
{
  if (i == j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (pal[i][j])
    return dp[i][j] = 0;

  int minCost = INT_MAX;
  for (int k = i; k < j; k++)
  {
    minCost = min(minCost, 1 + getMinCut(s, i, k, dp, pal) + getMinCut(s, k + 1, j, dp, pal));
  }
  return dp[i][j] = minCost;
}

int getMinCutOp(string &s, vector<vector<bool>> &pal)
{
  int n = s.size();
  vector<int> dp(n + 1, INT_MAX);
  // dp[i] represents the min cuts to palin part s[0...i]
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (pal[j - 1][i - 1])
      {
        if (j - 1 == 0)
          dp[i] = 0;
        else
          dp[i] = min(dp[i], dp[j - 1] + 1);
      }
    }
  }

  return dp[n];
}

int minCut(string &s)
{
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));

  vector<vector<bool>> pal(n, vector<bool>(n, false));

  // Length 1 all are palindromes
  for (int i = 0; i < n; i++)
    pal[i][i] = true;

  // Length 2
  for (int i = 0; i < n - 1; i++)
    pal[i][i + 1] = (s[i] == s[i + 1]);

  for (int len = 3; len <= n; len++)
  {
    for (int i = 0; i <= n - len; i++)
    {
      int j = i + len - 1;
      pal[i][j] = ((s[i] == s[j]) && pal[i + 1][j - 1]);
    }
  }

  // Still gives TLE
  // return getMinCut(s, 0, n - 1, dp, pal);

  return getMinCutOp(s, pal);
}

int main()
{

  return 0;
}