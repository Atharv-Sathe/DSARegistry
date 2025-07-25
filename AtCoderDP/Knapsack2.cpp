#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
  https://atcoder.jp/contests/dp/tasks/dp_e
*/

const long long infi = 1e18;

int tabulation(vector<pair<long long, int>>& items, long long W) {
  int n = items.size();
  // This dp[i] represents the min weight
  // to achieve a total value of i
  vector<long long> dp(1e5 + 1, infi);

  dp[0] = 0; // Take 0 weight to achieve value 0; 

  for (int i = 0; i < n; i++) {
    for (int j = 1e5; j >= items[i].second; j--) {
      if (dp[j - items[i].second] != infi) {
        dp[j] = min(dp[j], dp[j - items[i].second] + items[i].first);
      }
    }
  }

  for (int i = 1e5; i >= 0; i--) {
    if (dp[i] <= W) return i;
  }
  return 0;
}


int main() {
  int n;
  cin >> n;
  long long W;
  cin >> W;
  vector<pair<long long, int>> items(n);
  for (int i = 0; i < n; i++) {
    long long w;
    cin >> w;
    int v;
    cin >> v;
    items[i] = pair<long long, int>({w, v});
  }
  cout << tabulation(items, W);
}