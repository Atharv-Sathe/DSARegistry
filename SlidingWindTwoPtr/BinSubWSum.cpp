/*
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.
*/

#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    int prefixSum = 0;
    unordered_map<int, int> map;
    map[prefixSum] = 1;
    int count = 0;
    for (int i: nums) {
    prefixSum += i;
    if (map.count(prefixSum - goal)) count += map[prefixSum - goal];
    map[prefixSum]++;
    } 
    return count;
}

int main() {
    
    return 0;
}