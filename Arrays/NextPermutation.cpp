#include <bits/stdc++.h>
using namespace std;

// int smallestToRight(vector<int> &v, int i) {
//     // Returns the index of smallest integer to the right of v[i] which is greater than v[i];
//     int ans;
//     int smallestInt = INT_MAX;
//     for (int j = i + 1; j < v.size(); j++) {
//         if ((v[j] > v[i]) && v[j] <= smallestInt) {
//             ans = j;
//             smallestInt = v[j];
//         }
//     }
//     return ans;
// }
void nextPermutation(vector<int>& nums) {
    // Approach 1
    int n = nums.size();
    // for (int i = n - 1; i >= 0; i--) {
    //     if (i > 0 && nums[i - 1] < nums[i]) {
    //         int temp = smallestToRight(nums, i - 1);
    //         swap(nums[i - 1], nums[temp]);
    //         reverse(nums.begin() + i, nums.end());
    //         return;
    //     }
    // }

    // sort(nums.begin(), nums.end());

    // Approach 2 
    // next_permutation(nums.begin(), nums.end());

    // Approach 3
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            // Finding smallest num to the right of i greater than i;
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
            // Imp to note that the array from i+1th index to end is sorted in decreasing order now.
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    sort(nums.begin(), nums.end());
}


int main() {
    
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    nextPermutation(nums);
    for (int &n: nums) {
        cout << n << " ";
    }
    

    return 0;
}