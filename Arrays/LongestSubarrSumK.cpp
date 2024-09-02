// Find the longest sub array with sum K.

#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    int maxLen = 0;
    unordered_map<int, int> map;
    int prefixSum = 0;
    for (int i = 0; i < N; i++) {
        prefixSum += A[i];
        if (prefixSum == K) maxLen = i + 1;
        else if (map.count(prefixSum - K)) {
            maxLen = max(maxLen, i - map[prefixSum - K]);
        } 
        
        if (!map.count(prefixSum)) map[prefixSum] = i;
    }
    return maxLen;
}

int main() {
    
    return 0;
}