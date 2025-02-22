#include <iostream>
#include <stack>
using namespace std;

/*
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
*/

int maxLength(string& s) {
  stack<int> st;
  st.push(-1);
  int maxL = 0;
  for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
          st.push(i);
      } else {
          st.pop();
          if (st.empty()) st.push(i);
          else {
              maxL = max(maxL, i - st.top());
          }
      }
  }
  return maxL;
}

int main() {
  
  return 0;
}