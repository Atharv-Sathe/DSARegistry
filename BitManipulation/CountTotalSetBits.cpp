#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n)
{
    int k = 1;
    int ans = 0;
    while(k<=n){
        ans += ((n+1)/(2*k))*k;
        ans += max(0, (n+1)%(2*k) - k);
        k *= 2;
    }
    return ans;
}
int main() {
    
    return 0;
}
