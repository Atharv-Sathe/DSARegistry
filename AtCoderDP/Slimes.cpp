#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define ull unsigned long long

vector<ull> getNewSlimes(vector<ull>& slimes, int i) {
  int n = slimes.size();
  vector<ull> newVect;
  for (int j = 0; j < n; j++) {
    if (j == i) {
      newVect.push_back(1ull * slimes[j] + slimes[j + 1]);
      j++;
      continue;
    }
    newVect.push_back(1ull * slimes[j]);
  }
  return newVect;
}

ull naiveRecursion1(vector<ull>& slimes) {
  int n = slimes.size();
  if (n == 1) return 0;
  
  ull minCost = ULLONG_MAX;
  for (int i = 0; i < n - 1; i++) {
    vector<ull> newSlimes = getNewSlimes(slimes, i);
    ull cost = 1ull * slimes[i] + slimes[i + 1] + naiveRecursion1(newSlimes);
    minCost = min(minCost, cost);
  }
  return minCost;
}

vector<ull> pefixSum;
ull memoization(vector<ull>& slimes, int i, int j, vector<vector<ull>>& dp) {
  // Only 1 slime left
  if (j == i) {
    return 0;
  }
  if (dp[i][j] != -1) return dp[i][j];

  ull minCost = ULLONG_MAX;
  ull sum = pefixSum[j + 1] - pefixSum[i];
  // make a split from i to j - 1
  for (int k = i; k < j; k++) {
    ull cost = memoization(slimes, i, k, dp) + memoization(slimes, k + 1, j, dp);
    minCost = min(minCost, sum + cost);
  }
  return dp[i][j] = minCost;
}

ull solve(vector<ull>& slimes) {
  // return naiveRecursion1(slimes);
  int n = slimes.size();
  vector<vector<ull>> dp(n, vector<ull>(n, -1));
  return memoization(slimes, 0, n - 1, dp);
}


int main() {
  pefixSum.push_back(0);
  int n; cin >> n;
  vector<ull> slimes(n);
  for (int i = 0; i < n; i++) {
    cin >> slimes[i];
    pefixSum.push_back(pefixSum.back() + slimes[i]);
  }
  cout << solve(slimes) << endl;
}
