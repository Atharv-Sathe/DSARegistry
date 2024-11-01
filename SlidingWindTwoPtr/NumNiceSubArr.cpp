#include <bits/stdc++.h>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    // Approach  - 1 : Convert all odds to 1 and even's to 0, then count sub arrays with sum k
    // vector<int> numsMod;
    // for (int i : nums) {
    //     if (i % 2 == 0) numsMod.push_back(0);
    //     else numsMod.push_back(1);
    // }

    // int prefixSum = 0;
    // unordered_map<int, int> map;
    // map[prefixSum] = 1;
    // int count = 0;
    // for (int i: numsMod) {
    //     prefixSum += i;
    //     if (map.count(prefixSum - k)) count += map[prefixSum - k];
    //     map[prefixSum]++;
    // } 
    // return count;

    // Approach - 2 : Storing Indices of Odd Numbers
    // vector<int> oddIndices;
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] % 2 != 0) oddIndices.push_back(i);
    // }

    // // If there are fewer than k odd numbers, there are no nice subarrays
    // if (oddIndices.size() < k) return 0;

    // int count = 0;
    // for (int i = 0; i <= oddIndices.size() - k; i++) {
    //     int left = oddIndices[i];
    //     int right = oddIndices[i + k - 1];

    //     int rightExtension, leftExtension;

    //     // Extending left
    //     if (i == 0) { 
    //         leftExtension = left + 1;
    //     } else { // Extending to just previous odd number
    //         leftExtension = left -  oddIndices[i - 1];
    //     }

    //     // Extending right
    //     // Important to note that if suppose rightExtension is not possible
    //     // then the value of rightExtension should be 1 and not 0, since 
    //     // later multiplying with left extension would give 0
    //     if (i + k == oddIndices.size()) {
    //         rightExtension = nums.size() - right;
    //     } else {
    //         rightExtension = oddIndices[i + k] - right;
    //     }

    //     count += leftExtension * rightExtension;
    // }
    // return count;

    // Approach - 3 : Two Pointer
    int oddCount = 0;
    int niceSub = 0, prefix = 0;
    int i = 0, j = 0;
    while (j < nums.size()) {
        if (nums[j] % 2 != 0) {
            oddCount++;
            prefix = 0;
        }   
        while(oddCount == k) {
            prefix++;
            if (nums[i] % 2 != 0) oddCount--;
            i++;
        }
        niceSub += prefix;
        j++;
    }
    return niceSub;
}

int main() {
    
    return 0;
}