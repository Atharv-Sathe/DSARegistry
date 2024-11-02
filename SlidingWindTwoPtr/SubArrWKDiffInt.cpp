/*
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.
*/


#include <bits/stdc++.h>
using namespace std;

int atMostKDisctinct(vector<int>& nums, int k) {
    int count = 0, right = 0, left = 0;
    unordered_map<int, int> freq;
    while(right < nums.size()) {
        if (freq[nums[right]]++ == 0) k--;

        while(k < 0) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) k++;
            left++;
        }

        count += right - left + 1;
        right++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return atMostKDisctinct(nums, k) - atMostKDisctinct(nums, k - 1);
}

int main() {
    vector<int> v;
    int k;
    // v = {1,2,3,1,2,3};
    v = {1,1,1,3,2};
    k = 3;
    cout << subarraysWithKDistinct(v, k) << endl;


    return 0;
}