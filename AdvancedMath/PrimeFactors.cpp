#include <bits/stdc++.h>
using namespace std;

vector<int> modifiedSieve(int n) {
    if (n <= 1) return {};
    vector<int> isPrime(n, true);
    vector<int> SPF(n, 0);
    vector<int> prime;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
            SPF[i] = i;
        }
        
        for (int j = 0;
            j < prime.size() &&
            (long long)i * prime[j] < n &&
            prime[j] <= SPF[i];
            j++
        ) {
            isPrime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
    return prime;
}

vector<int>AllPrimeFactors(int N) {
    if (N <= 1) return {};
    vector<int> allPrimes = modifiedSieve(N + 1);
    vector<int> ans;
    for (int i: allPrimes) {
        if (N % i == 0) ans.push_back(i);
    }
    return ans;
}

int main() {
    
    return 0;
}