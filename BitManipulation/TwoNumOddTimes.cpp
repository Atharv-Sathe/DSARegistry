#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{   
    long long int allXOR = Arr[0];
    for (int i = 1; i < N; i++) {
        allXOR ^= Arr[i];
    }
    // Finding rightmost set bit
    int rightMostSet = __builtin_popcount(allXOR ^ (allXOR - 1)) - 1; // Gives the index (0 based)
    long long int grpAxor = 0, grpBxor = 0;
    for (int i = 0; i < N; i++) {
        // If rightMostSet bit is set, then grp A, else grp B
        if ((Arr[i] >> rightMostSet) & 1) grpAxor ^= Arr[i];
        else grpBxor ^= Arr[i];
    }
    
    if (grpAxor > grpBxor) return {grpAxor, grpBxor}; 
    return {grpBxor, grpAxor};
    
}

int main() {
    
    return 0;
}