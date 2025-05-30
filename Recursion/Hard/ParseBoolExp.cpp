#include <iostream>
#include <stack>
using namespace std;

/*
A boolean expression is an expression that evaluates to either true or false.
It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner
expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner
expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of
that expression.

It is guaranteed that the given expression is valid and follows the given rules.
*/

int getCorrespondingClosingInd(string &exp, int strt)
{
  stack<char> st;
  int i;
  for (i = strt; i < exp.size(); i++)
  {
    if (exp[i] == '(')
      st.push('(');
    else if (exp[i] == ')')
      st.pop();
    if (st.empty())
      break;
  }
  return i;
}

bool solveExpr(string &exp, int i)
{

  bool res;
  if (exp[i] == '!')
    return !solveExpr(exp, i + 2);
  else if (exp[i] == '&')
    res = true;
  else if (exp[i] == '|')
    res = false;
  else
    return (exp[i] == 'f') ? false : true;

  int k = i + 2;
  while (exp[k] != ')')
  {
    if (exp[k] == ',')
    {
      k++;
      continue;
    }
    else if (exp[k] == '&' || exp[k] == '|' || exp[k] == '!')
    {
      if (exp[i] == '&')
        res &= solveExpr(exp, k);
      else
        res |= solveExpr(exp, k);

      // Move k to one position after corresponding closing bracket
      k = getCorrespondingClosingInd(exp, k + 1) + 1;
    }
    else
    {
      bool tempRes = (exp[k] == 'f') ? false : true;
      if (exp[i] == '&')
        res &= tempRes;
      else
        res |= tempRes;
      k++;
    }
  }
  return res;
}

bool parseBoolExpr(string expression)
{
  return solveExpr(expression, 0);
}

int main()
{

  return 0;
}