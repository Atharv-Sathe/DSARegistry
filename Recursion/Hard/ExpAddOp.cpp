#include <iostream>
#include <vector>
#include <string>
using namespace std;

void backtrack(string& num, int target, int index, string currExp, long currVal, 
long prevNum, vector<string>& result) {
    // Base Case
    if (index == num.length()) {
        if (currVal == target) result.push_back(currExp);
        return;
    } 

    string numStr;
    long currNum = 0;

    for (int i = index; i < num.length(); i++) {        
        // Handle leading zeros
        if (i != index && num[index] == '0') break;

        numStr += num[i];
        currNum = currNum * 10 + (num[i] - '0');

        // No Operator needed if expression start
        if (index == 0) {
            backtrack(num, target, i + 1, numStr, currNum, currNum, result);
            continue;
        }

        // Try Addition
        backtrack(num, target, i + 1, currExp + "+" + numStr, 
        currVal + currNum, currNum, result);

        // Try Subtraction
        backtrack(num, target, i + 1, currExp + "-" + numStr, 
        currVal - currNum, -currNum, result);

        // Try Multiplication
        backtrack(num, target, i + 1, currExp + "*" + numStr,
        currVal - prevNum + (prevNum * currNum), prevNum * currNum, result);
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> result;
    if (num.empty()) return result;
    backtrack(num, target, 0, "", 0, 0, result);
    return result;
}

int main() {
    
    return 0;
}