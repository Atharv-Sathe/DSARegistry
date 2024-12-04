#include <bits/stdc++.h>
using namespace std;

double recurPow(double x, int ex) {
    if (ex == 0) return 1;
    double temp = recurPow(x, ex/2);

    if (ex % 2 == 0) {
        return temp * temp;
    } else {
        if (ex > 0) {
            return x * temp * temp;
        } else {
            return (temp * temp) / x;
        }
    }
}


int main() {
    double x = 50;
    int ex = 18;

    cout << recurPow(x, ex) << "\n";

    return 0;
}