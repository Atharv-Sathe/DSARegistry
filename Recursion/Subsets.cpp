/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, int start, vector<int> current, vector<vector<int>>& results) {
    results.push_back(current);
    for(int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(nums, i + 1, current, results);
        current.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    // Optimized Bit Manipulation
    // int n = nums.size();
    // int totalSubsets = (1 << n);
    // vector<vector<int>> subsets;
    // for (int i = 0; i < totalSubsets; i++) {
    //     vector<int> subset;
    //     for (int j = 0; j < n; j++) {
    //         if (i & (1 << j)) {
    //             subset.push_back(nums[j]);
    //         }
    //     }
    //     subsets.push_back(subset);
    // }
    // return subsets;

    // Backtracking Solution
    vector<vector<int>> results;
    vector<int> current;
    backtrack(nums, 0, current, results);
    return results;
}

int main() {
    
    return 0;
}