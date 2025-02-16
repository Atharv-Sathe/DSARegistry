#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
This question has a sexy logic very we will be taking into count the 
duplicates only one time, either in creating left or in creating right.
*/
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n, 0), right(n, 0);
    stack<int> incS, incSR;
    // Create arr to store dist b/w an elem and its prev smlst elem
    int j;
    for (int i = 0; i < n; i++) {
        while(!incS.empty() && arr[incS.top()] > arr[i]) incS.pop();
        left[i] = incS.empty() ? (i + 1) : (i - incS.top());
        incS.push(i);
        // j = n - i - 1;
        // while(!incSR.empty() && arr[incSR.top()] >= arr[j]) incSR.pop();
        // right[j] = incSR.empty() ? (n - j) : (incSR.top() - j);
        // incSR.push(j);
    }
    incS = stack<int>();
    // Create arr to store dist b/w an elem and its next smlst elem
    for (int i = n - 1; i >= 0; i--) {
        while(!incS.empty() && arr[incS.top()] >= arr[i]) incS.pop();
        right[i] = incS.empty() ? (n - i) : (incS.top() - i);
        incS.push(i);
    }

    int sum = 0, mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        sum = (sum + (long long)arr[i] * left[i] * right[i]) % mod;
    }
    return sum;
}

int main() {
    
    return 0;
}