#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] 
is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its 
traversing-order next in the array, which means you could search circularly 
to find its next greater number. If it doesn't exist, return -1 for this number.
*/

void createRes(vector<int>& nums, stack<int>& s, vector<int>& res) {
    for (int i = nums.size() - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= nums[i]) s.pop();
        if (!s.empty()) res[i] = s.top();
        else res[i] = -1;
        s.push(nums[i]);
    }
}

vector<int> nextGreaterElements(vector<int>& nums) {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    stack<int> s;
    vector<int> res(nums.size(), 0);
    createRes(nums, s, res);
    createRes(nums, s, res);
    return res;
}

int main() {
    
    return 0;
}
