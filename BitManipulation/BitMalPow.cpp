#include <bits/stdc++.h>
using namespace std;

double bitPow(double x, int ex) {

    if (x == 0) return 0;
    if (ex == 0) return 1;

    long long N = ex;

    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double res = 1;
    while (N > 0) {
        if (N & 1) {
            res *= x;
        }

        x *= x;
        N >>= 1;
    }
    return res;
}

int main() {
    double x = 5;
    int ex = -2;

    cout << bitPow(x, ex) << "\n";

    return 0;
}