#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getSubsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubsets = (1 << n);
    vector<vector<int>> subsets;
    for (int i = 0; i < totalSubsets; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}


int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = getSubsets(nums);
    for (const auto& v: subsets) {
        cout << "{";
        for (const auto& i: v) {
            cout << i << " ";
        }
        cout << "}\n";
    }
    return 0;
}
