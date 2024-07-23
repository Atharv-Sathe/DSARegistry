#include <bits/stdc++.h>
using namespace std;

int divideAndConquer(vector<int>&arr, int left, int right);
int maxSubArray(vector<int>&nums) {
    // Brute Force Approach but works TLE at testcase 203 | O(n^2);
    // int size = nums.size();
    // int ultMaxSum = INT_MIN;
    // int currMaxSum = INT_MIN;
    // int currSum;
    // int winSize = 1;
    // for (winSize; winSize <= size; winSize++) {
    //     int i = 0, j = i + winSize - 1;
    //     currSum = accumulate(nums.begin(), nums.begin() + i + winSize, 0);
    //     currMaxSum = currSum;
    //     while(j < size - 1) {
    //         currSum += nums[j + 1] - nums[i];
    //         j++;
    //         i++;
    //         if (currSum > currMaxSum) currMaxSum = currSum;
    //     }
    //     if (currMaxSum > ultMaxSum) ultMaxSum = currMaxSum;
    // } 
    // return ultMaxSum;

    // Kadane's Algorithm : O(n)
    // int size = nums.size();
    // if (size == 0) return 0;

    // int maxCurr = 0;
    // int maxGlob = INT_MIN;

    // for (auto n: nums) {
    //     maxCurr = max(n, maxCurr + n);
    //     maxGlob = max(maxCurr, maxGlob);
    // }

    // return maxGlob; 

    // Divide and Conquer
    return divideAndConquer(nums, 0, nums.size() - 1);
}

int divideAndConquer(vector<int>&arr, int left, int right) {
    if (left > right) return INT_MIN;
    
    int mid = (left + right) / 2, leftSum = 0, rightSum = 0;

    for (int i = mid - 1, curSum = 0; i >= left; i--) {
        curSum += arr[i];
        leftSum = max(curSum, leftSum);
    }

    for (int i = mid + 1, curSum = 0; i <= right; i++) {
        curSum += arr[i];
        rightSum = max(curSum, rightSum);
    }

    return max({divideAndConquer(arr, left, mid - 1), divideAndConquer(arr, mid + 1, right), leftSum + arr[mid] + rightSum});
}


int main() {
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    // v = {5,4,-1,7,8};
    cout << maxSubArray(v) << endl;
    return 0;
}