#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long tabulation(vector<pair<int, int>>& items, int W) {
  int n = items.size();
  vector<long long> wt(W + 1, 0);
  for (int i = 0; i < W + 1; i++) {
    if (i < items[n - 1].first)
      wt[i] = 0;
    else
      wt[i] = 1ll * items[n - 1].second;
  }

  for (int i = n - 2; i >= 0; i--) {
    vector<long long> tempWt(W + 1, -1);

    for (int j = 0; j <= W; j++) {
      // No take curItem
      tempWt[j] = wt[j];

      // Take curItem
      if (j - items[i].first >= 0) {
        long long take = items[i].second + wt[j - items[i].first];
        tempWt[j] = max(tempWt[j], take);
      }
    }
    wt = tempWt;
  }

  return *max_element(begin(wt), end(wt));
}

long long memoization(vector<pair<int, int>>& items, int W, int i, int curWt,
                vector<vector<long long>>& dp) {
  if (i >= (int)items.size()) return 0;
  if (dp[i][curWt] != -1) return dp[i][curWt];

  long long take = -1;
  if (curWt + items[i].first <= W) {
    take = items[i].second +
           memoization(items, W, i + 1, curWt + items[i].first, dp);
  }

  long long noTake = memoization(items, W, i + 1, curWt, dp);

  return dp[i][curWt] = max(take, noTake);
}

int main() {
  int n;
  cin >> n;
  int W;
  cin >> W;
  vector<pair<int, int>> items(n);
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    int v;
    cin >> v;
    items[i] = pair<int, int>({w, v});
  }
  cout << tabulation(items, W);
  // vector<vector<long long>> dp(n, vector<long long>(W + 1, -1));
  // cout << memoization(items, W, 0, 0, dp);
}