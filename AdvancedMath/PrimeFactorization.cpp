#include <bits/stdc++.h>
using namespace std;

vector<int> sieveM(int n) {
    vector<int> spf(n + 1, 1);
    spf[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 1) {
            // i is a prime number
            for(int j = i; j <= n; j += i) {
                if (spf[j] == 1) spf[j] = i; // If spf hasn't been found yet
            }
        }
    }
    return spf;
}


vector<int> findPrimeFactors(int N) {

    vector<int> spf = sieveM(N);
    vector<int> ans;
    while (N != 1) {
        ans.push_back(spf[N]);
        N /= spf[N];
    }
    return ans;
}

int main() {
    
    return 0;
}