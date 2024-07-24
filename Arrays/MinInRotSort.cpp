#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0]; // Array has one element
    int l = 0, r = n - 1;
    int mid, ans;
    // Dealing with edge cases
    if (nums[0] < nums[r]) return nums[0]; // Array unrotated

    while(l <= r) {
        mid = l + (r - l) / 2;
        if (mid > 0 && nums[mid] < nums[mid - 1]) {
            ans = nums[mid];
            break;
        }
        if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
            ans = nums[mid + 1];
            break;
        }
        if (nums[mid] >= nums[l]) l = mid + 1;
        else r = mid - 1; 
    }
    return ans;
}

int main() {
    
    vector<int> v = {4,5,6,7,0,1,2};
    cout << findMin(v) << endl;
    return 0;
}