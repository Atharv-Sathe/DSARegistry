#include <bits/stdc++.h>
using namespace std;

// Infix to Postfix
string infixToPostfix(string s) {
    stack<char> operators;
    unordered_map<char, int> priority = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1},
        {'(', 0},
        {')', 0}
    };
    string ans = "";
    for (char c: s) {
        if (priority.count(c) == 0) ans += c;
        else {
            if (c == '(') operators.push(c);
            else if (c == ')') {
                while (operators.top() != '(') {
                    ans += operators.top();
                    operators.pop();
                }
                operators.pop(); // This is to remove the '(' from top.
            }
            else {
                while(!operators.empty() && (priority[operators.top()] >= priority[c])) {
                    ans += operators.top();
                    operators.pop();
                }
                operators.push(c);
            } 
        }
    }
    while(!operators.empty()) {
        ans += operators.top();
        operators.pop();
    }
    
    return ans;
}

// Infix to Prefix
string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    stack<char> operators;
    unordered_map<char, int> priority = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1},
        {'(', 0},
        {')', 0}
    };
    string ans = "";
    for (char c: s) {
        if (priority.count(c) == 0) ans += c;
        else {
            if (c == ')') operators.push('('); // Treating opening bracket as closed and closed as open since we reversed the s
            else if (c == '(') {
                while (operators.top() != '(') {
                    ans += operators.top();
                    operators.pop();
                }
                operators.pop(); // This is to remove the '(' from top.
            }
            else {
                while(!operators.empty() && (priority[operators.top()] > priority[c])) {
                    ans += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
    }
    while(!operators.empty()) {
        ans += operators.top();
        operators.pop();
    }
    // Reversing the nearly postfix expression
    reverse(ans.begin(), ans.end());
    return ans;
}

// Prefix to Infix
void giveMeInfixExp(stack<string>& st, string op) {
    string c1 = st.top();
    st.pop();
    string c2 = st.top();
    st.pop();
    st.push("(" + c1 + op + c2 + ")");
}

string preToInfix(string pre_exp) {
    stack<string> exp;
    set<char> operators = {'+', '-', '*', '/', '%', '^'};
    for (int i = pre_exp.size() - 1; i >= 0; i--) {
        if (operators.count(pre_exp[i]) == 0) exp.push(string(1, pre_exp[i]));
        else giveMeInfixExp(exp, string(1, pre_exp[i]));
    }
    return exp.top();
}

// Prefix to Postfix
void giveMePostfixExp(stack<string>& st, string op) {
    string c1 = st.top();
    st.pop();
    string c2 = st.top();
    st.pop();
    st.push(c1 + c2 + op);
}

string preToPost(string pre_exp) {
    stack<string> exp;
    set<char> operators = {'+', '-', '*', '/', '%', '^'};
    for (int i = pre_exp.size() - 1; i >= 0; i--) {
        if (operators.count(pre_exp[i]) == 0) exp.push(string(1, pre_exp[i]));
        else giveMePostfixExp(exp, string(1, pre_exp[i]));
    }
    return exp.top();        
}

// Postfix to Prefix
void giveMePrefixExp(stack<string>& st, string op) {
    string c1 = st.top();
    st.pop();
    string c2 = st.top();
    st.pop();
    st.push(op + c2 + c1);
}

string postToPre(string post_exp) {
    stack<string> exp;
    set<char> operators = {'+', '-', '*', '/', '%', '^'};
    for (int i = 0; i < post_exp.size(); i++) {
        if (operators.count(post_exp[i]) == 0) exp.push(string(1, post_exp[i]));
        else giveMePrefixExp(exp, string(1, post_exp[i]));
    }
    return exp.top();        // Write your code here
}

// Postfix to Infix
void giveMeExp(stack<string>& st, char op) {
    string c1 = st.top();
    st.pop();
    string c2 = st.top();
    st.pop();
    st.push("(" + c2 + op + c1 + ")");
}

string postToInfix(const string& exprn) {
    // stack<string> exp;
    // set<char> operators = {'+', '-', '*', '/', '%', '^'};
    // for (int i = 0; i < exprn.size(); i++) {
    //     if (operators.count(exprn[i]) == 0) exp.push(string(1, exprn[i]));
    //     else giveMeExp(exp, exprn[i]);
    // }
    // return exp.top(); 
    
    set<char> operators = {'+', '-', '*', '/', '%', '^'};
    vector<string> stack;
    
    for (const char& c: exprn) {
        if (operators.count(c)) {
            string c1 = stack.back(); stack.pop_back();
            string c2 = stack.back(); stack.pop_back();
            stack.push_back("(" + c2 + c + c1 + ")");
        } else {
            stack.push_back(string(1, c));
        }
    }
    return stack.back();
}

int main() {
    
    string exprn;
    exprn = "(A-B/C)*(A/K-L)";
    cout << infixToPrefix(exprn) << endl;

    return 0;
}