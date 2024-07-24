#include <bits/stdc++.h>
using namespace std;

// Two Pointer Approach | O(n^2)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp(3);
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int L = i + 1;
        int R = n - 1;
        int target = -nums[i];
        while(L < R) {
            int sum = nums[L] + nums[R];
            if (sum == target) {
                temp[0] = nums[i];
                temp[1] = nums[L];
                temp[2] = nums[R];
                ans.push_back(temp);
                while(L < R && nums[L] == nums[L + 1]) L++;
                while(L < R && nums[R] == nums[R - 1]) R--;
                L++;
                R--;
            } else if (sum < target) L++;
            else R--;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {-1,0,1,2,-1,-4};
    for (auto triplets: threeSum(v)) {
        for (auto t: triplets) {
            cout << t << " ";
        }
        cout << endl;
    }

    return 0;
}