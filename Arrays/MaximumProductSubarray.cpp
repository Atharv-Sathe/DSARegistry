#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
    // Brute Force Approach  | O(n^2)
    // int size = nums.size();
    // if (size == 0) return 0;
    // long long maxProd = INT_MIN;
    // long long curProd;
    // for (int i = 0; i < size; i++) {
    //     curProd = nums[i];
    //     maxProd = max(curProd, maxProd);
    //     for (int j = i + 1; j < size; j++) {
    //         curProd *= nums[j];
    //         maxProd = max(curProd, maxProd);
    //     }
    // }

    // return maxProd;
    
    // Optimized intuitive approach | O(n)
    // int n = nums.size();
    // // Handling arr with size 1
    // if (n == 1) return nums[0];
    // int pref = 1, suff = 1;
    // int ans = INT_MIN;
    // for (int i = 0; i < n; i++) {
    //     if (pref == 0) pref = 1;
    //     if (suff == 0) suff = 1;

    //     pref *= nums[i];
    //     suff *= nums[n - i - 1];
    //     ans = max({ans, pref, suff});
    // }
    // return ans;

    // Dynamic Programming Approach to handle signed integer overflow
    int n = nums.size();
    double maxProd = nums[0];
    double minProd = nums[0];
    double result = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) {
            double temp = maxProd;
            maxProd = minProd;
            minProd = temp;
        }

        maxProd = max(static_cast<double>(nums[i]), maxProd * nums[i]);
        minProd = min(static_cast<double>(nums[i]), minProd * nums[i]);
        result = max(result, maxProd);

    }
    return static_cast<int>(result);
}

int main() {
    vector<int> v = {2,3,-2,4};
    // v = {5,4,-1,7,8};
    
    cout << maxProduct(v) << endl;

    return 0;
}