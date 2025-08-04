#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/dp/tasks/dp_m
*/

const int MOD = 1e9 + 7;

/*
 * Approach Explanation: Dynamic Programming with Sliding Window Optimization
 *
 * 1. The DP State:
 * - We define `dp[i][j]` as the number of ways to distribute exactly `j`
 * candies among the first `i` children (children 0 to i-1), respecting each
 * child's limit.
 * - Our final answer will be `dp[N][K]`.
 *
 * 2. The Naive Recurrence (and why it's too slow):
 * - To calculate `dp[i][j]`, we consider the i-th child. This child can take
 * `c` candies, where `0 <= c <= a_{i-1}` (their individual limit).
 * - If the i-th child takes `c` candies, then the remaining `j-c` candies must
 * be distributed among the first `i-1` children. The number of ways for that is
 * `dp[i-1][j-c]`.
 * - So, we must sum this over all possible values of `c`:
 * `dp[i][j] = sum(dp[i-1][j-c])` for `c` from `0` to `a_{i-1}`.
 * - This approach is too slow because it requires a third loop for `c`, leading
 * to a time complexity of roughly O(N * K * max_a), which will time out.
 *
 * 3. The Optimization (Sliding Window / Prefix Sums):
 * - The key observation is that the sum for `dp[i][j]` is very similar to the
 * sum for `dp[i][j-1]`.
 * - Sum for `dp[i][j]`   = `dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j - a_i]`
 * - Sum for `dp[i][j-1]` = `             dp[i-1][j-1] + ... + dp[i-1][j - a_i]
 * + dp[i-1][j-1-a_i]`
 *
 * - To get the sum for `j` from the sum for `j-1`, we can see it's a "sliding
 * window". We add the new term `dp[i-1][j]` and subtract the old term
 * `dp[i-1][j-1-a_i]` that is no longer part of the sum.
 * - This gives us the efficient recurrence:
 * `dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j - a_{i-1} - 1]`
 *
 * 4. Implementation Details in this Code:
 * - The ternary `(can - candies[i-1] - 1 < 0)` checks if we need to subtract
 * the old term. If the index would be negative, it means the window hasn't
 * reached its full size yet, so we only do the addition part: `dp[i-1][can] +
 * dp[i][can-1]`.
 * - The `+ MOD` is crucial for modular subtraction. In C++, `(A - B) % MOD` can
 * be negative if `A < B`. `(A - B + MOD) % MOD` correctly handles all cases.
 */

int solveTab(vector<int>& candies, int k) {
  int n = candies.size();

  // dp[i][j] represents the number of ways to distribute
  // a total of j candies to i children (0 ~ i - 1)
  vector<vector<long>> dp(n + 1, vector<long>(k + 1, 0));

  // There is only one way to give 0 candies to n children
  for (int i = 1; i <= n; i++) dp[i][0] = 1;

  // There is only one way to give k candies to 1 child where 0 <= k <=
  // candies[0]
  for (int can = 0; can <= candies[0]; can++) dp[1][can] = 1;

  for (int i = 2; i <= n; i++) {
    for (int can = 1; can <= k; can++) {
      dp[i][can] = ((can - candies[i - 1] - 1 < 0)
                        ? (dp[i - 1][can] + dp[i][can - 1])
                        : (dp[i - 1][can] + dp[i][can - 1]) -
                              dp[i - 1][can - candies[i - 1] - 1] + MOD) %
                   MOD;
    }
  }
  return static_cast<int>(dp[n][k]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int k;
  cin >> k;

  vector<int> candies(n);
  for (int i = 0; i < n; i++) cin >> candies[i];

  cout << solveTab(candies, k);
  return 0;
}