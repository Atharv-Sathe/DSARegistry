#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
using namespace std;

/*
Given an integer array nums, return true if you can partition the array into two subsets such 
that the sum of the elements in both subsets is equal or false otherwise.
*/

    bool recurse(vector<int>& nums, int totalSum, unordered_set<int>& selected, int currentSum) {
        if (currentSum == totalSum / 2) return true;
        
        if (selected.size() == nums.size() - 1) {
            return (totalSum / 2 == currentSum) ? true : false;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (selected.count(i)) continue;
            selected.insert(i);
            if (recurse(nums, totalSum, selected, currentSum + nums[i])) return true;
            selected.erase(i);
        }

        return false;
    }

    // TC: O(n * sum) SC: O(n * sum) + O(n)  
    bool memoization(vector<int>& nums, int totalSum, vector<vector<bool>>& memo, int i, int sum) {
        if (i == nums.size()) return (sum == totalSum / 2) ? true : false;
        if (!memo[i][sum]) return false;

        // Select the current element
        if (memoization(nums, totalSum, memo, i + 1, sum + nums[i])) return true;

        // Not Select the current element
        if (memoization(nums, totalSum, memo, i + 1, sum)) return true;

        return memo[i][sum] = false;
    }


    int tabulation(vector<int>& nums, int totalSum) {
        int n = nums.size();
        vector<vector<bool>> tab(n, vector<bool>(totalSum + 1, false));
        tab[0][0] = true; 
        tab[0][nums[0]] = true;


        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= totalSum; j++) {
                // Not Selecting the current index
                bool noTake = tab[i - 1][j];
                bool take = false;
                // Selecting the current index
                if (j - nums[i] >= 0 ) take = tab[i - 1][j - nums[i]]; 
                tab[i][j] = noTake || take;
            }
            if (tab[i][totalSum / 2]) return true;
        }

        return tab[n - 1][totalSum / 2];
    }

    int tabulationSpaceOp(vector<int>& nums, int totalSum) {
        int n = nums.size();
        vector<bool> tab(totalSum + 1, false);
        tab[0] = true; 
        tab[nums[0]] = true;

        for (int i = 1; i < nums.size(); i++) {
            vector<bool> temp(totalSum + 1, false);
            for (int j = 0; j <= totalSum; j++) {
                // Not Selecting the current index
                bool noTake = tab[j];
                bool take = false;
                // Selecting the current index
                if (j - nums[i] >= 0 ) take = tab[j - nums[i]]; 
                temp[j] = noTake || take;
            }
            if (temp[totalSum / 2]) return true; // Return earlier
            tab = temp;
        }

        return tab[totalSum / 2];
    }


    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;  
        // Naive Recursion
        // unordered_set<int> selected;
        // return recurse(nums, sum, selected, 0);

        // Memoization
        // vector<vector<bool>> memo(nums.size(), vector<bool>(sum + 1, true));
        // return memoization(nums, sum, memo, 0, 0);

        // Tabulation 
        // return tabulation(nums, sum);

        // Tabulation Space Op
        return tabulationSpaceOp(nums, sum);
    }

int main() {
  
  return 0;
}