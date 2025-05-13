#include <iostream>
#include <vector>
using namespace std;

/*
Given two strings str1 and str2, return the shortest string that
has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters
from t (possibly 0) results in the string s.
*/

string gtLgstCmnSubseq(string &str1, string &str2)
{
  int n = str1.size(), m = str2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (str1[i - 1] == str2[j - 1])
      {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  string res = "";
  int i = n, j = m;
  while (i > 0 && j > 0)
  {
    if (str1[i - 1] == str2[j - 1])
    {
      res += str1[i - 1];
      i--;
      j--;
    }
    else if (dp[i][j - 1] > dp[i - 1][j])
    {
      res += str2[j - 1];
      j--;
    }
    else
    {
      res += str1[i - 1];
      i--;
    }
  }

  while (i > 0)
    res += str1[i-- - 1];
  while (j > 0)
    res += str2[j-- - 1];

  reverse(res.begin(), res.end());
  return res;
}

string shortestCommonSupersequence(string str1, string str2)
{
  return gtLgstCmnSubseq(str1, str2);
}

int main()
{

  return 0;
}