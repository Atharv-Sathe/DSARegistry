#include <iostream>
#include <vector>
using namespace std;

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with
support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

bool getIsMatch(string &s, string &p, int i, int j, vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return true; // String and pattern both empty
  if (j == 0)
    return false; // Pattern is empty but string is not
  if (i == 0)
  {
    // String is empty, pattern matches only if all characters are '*'
    for (int k = 1; k <= j; k++)
    {
      if (p[k - 1] != '*')
        return false;
    }
    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];

  if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
    return dp[i][j] = getIsMatch(s, p, i - 1, j - 1, dp);
  else if (p[j - 1] == '*')
    return dp[i][j] = (getIsMatch(s, p, i, j - 1, dp) | getIsMatch(s, p, i - 1, j, dp));
  return dp[i][j] = false;
}

bool getIsMatchTab(string &s, string &p)
{
  int m = s.size(), n = p.size();
  vector<bool> curr(n + 1), prev(n + 1);
  prev[0] = true;
  for (int k = 1, flag = true; k <= n; k++)
  {
    if (flag && p[k - 1] != '*')
      flag = false;
    prev[k] = flag;
  }
  curr[0] = false;
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        curr[j] = prev[j - 1];
      else if (p[j - 1] == '*')
        curr[j] = (curr[j - 1] | prev[j]);
      else
        curr[j] = false;
    }
    prev = curr;
  }
  return prev[n];
}

int main()
{

  return 0;
}