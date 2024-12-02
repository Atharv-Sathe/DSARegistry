#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    if (dividend == INT_MIN && divisor == 1) return INT_MIN;
    bool isNeg = (dividend < 0) ^ (divisor < 0);
    unsigned int a, b;
    a = (dividend == INT_MIN) ? dividend : abs(dividend);
    b = (divisor == INT_MIN) ? divisor : abs(divisor);

    int ans{};
    for (int i{31}; i >= 0; i--) {
        if ((a >> i) >= b) {
            ans += 1 << i;
            a -= (b << i);
        }
    }
    return (isNeg) ? -ans : ans;
}

int main() {
    
    return 0;
}
