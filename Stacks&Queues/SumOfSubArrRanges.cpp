#include <iostream>
#include <stack>
#include <vector>
#define FL(a, b) for (int i = a; i <= b; i++)
using namespace std;

/*
You are given an integer array nums. The range of a subarray of 
nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long answer = 0;
    stack<int> stk;

    // Sum of minimums
    FL(0, n) {
        while(!stk.empty() && (i == n || nums[stk.top()] >= nums[i])) {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            answer -= (long long)nums[mid] * (i - mid) * (mid - left);
        }
        stk.push(i);
    }
    stk.pop();

    // Sum of maximums
    FL(0, n) {
        while(!stk.empty() && (i == n || nums[stk.top()] <= nums[i])) {
            int mid = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top();
            answer += (long long)nums[mid] * (i - mid) * (mid - left);
        }
        stk.push(i);
    }
    return answer;
}

int main() {
    
    return 0;
}