#include <bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums, int k, int maxSum) {
	int currentSum = 0;
	int subarrays = 1;
	for (int num: nums) {
		if (num > maxSum) return false;
		currentSum += num;
		if (currentSum > maxSum) {
			currentSum = num;
			subarrays++;
		}
		if (subarrays > k) return false;
	}
	return true;
}

int splitArray(vector<int>& nums, int k) {
	int left = *max_element(nums.begin(), nums.end()), right = accumulate(nums.begin(), nums.end(), 0);
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (canPartition(nums, k, mid)) {
			right = mid;
		} else {
			left = mid + 1;
		}
	} 
	return right;
}
int main() {
	
}
