#include <iostream>
#include <vector>
using namespace std;

// Sexy Tabulation
vector<int> sexyPrintTab(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, 1);

  // dp[i] represents the length of longest increasing subsequence ending at i
  int maxLen = 1;
  vector<int> hash(n, 0);
  int lastInd = 0;
  for (int i = 1; i < n; i++) {
    hash[i] = i;
    for (int j = i - 1; j >= 0; j--) {
      // For every element i we are checking selecting or not selecting which previous
      // element j will give us the max output and we will store this
      if (nums[j] < nums[i] && dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        hash[i] = j;
      }
    }
    if (maxLen < dp[i]) {
      lastInd = i;
      maxLen = dp[i];
    }
  }

  vector<int> res;
  int itr = lastInd;
  res.push_back(nums[itr]);
  while (hash[itr] != itr) {
    itr = hash[itr];
    res.push_back(nums[itr]);
  }

  return res;
}

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> lis = sexyPrintTab(nums);
  for (int i : lis) {
    cout << i << " ";
  }
  cout << endl;
return 0;
}