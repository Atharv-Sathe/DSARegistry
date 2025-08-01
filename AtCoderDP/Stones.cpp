#include <bits/stdc++.h>
using namespace std;

// Taro : 0 ; Jiro : 1
// This causes a runtime error when recursion is too deep
bool solveHelper(unordered_set<int>& stones, int minElem, int k, bool isJiro,
                 vector<vector<int>>& dp) {
  // Base Case
  if (k < minElem) return !isJiro;
  if (dp[k][isJiro] != -1) return dp[k][isJiro];

  // Even if we get one instance where the current player
  // wins then the current player will go for that move
  // since both players play optimally
  for (int i : stones) {
    if (k >= i) {
      if (isJiro == solveHelper(stones, minElem, k - i, !isJiro, dp)) {
        return dp[k][isJiro] = isJiro;
      }
    }
  }

  // If we get no move choosing which the current player can
  // win, these means irrespective of what move the current
  // player plays at this point they can never win, thus we
  // have our winner

  return dp[k][isJiro] = !isJiro;
}

bool solveHelperTab(unordered_set<int>& stones, int k) {
  int n = stones.size();
  int minElem = *min_element(stones.begin(), stones.end());
  vector<vector<bool>> dp(k + 1, vector<bool>(2, false));

  for (int i = 0; i < minElem; i++) {
    dp[i][0] = 1;
    dp[i][1] = 0;
  }

  for (int i = minElem; i <= k; i++) {
    for (int turn = 0; turn <= 1; turn++) {
      bool canCurrentWin = false;
      for (int j : stones) {
        if (i >= j) {
          if (turn == dp[i - j][!turn]) {
            dp[i][turn] = turn;
            canCurrentWin = true;
            break;
          } 
        }
      }
      if (!canCurrentWin) dp[i][turn] = !turn;
    }
  }

  return dp[k][0];
}

// When all remaining numbers in set > stones left in pile
// the player with current turn looses in other words when
// the stones in pile < 2 * (least number in set) or if
// the stones in pile = 2 * (least number in set) and the set has
// at least two elements then the current player
// would always win if they play optimally
bool solve(unordered_set<int>& stones, int k) {
  // int n = stones.size();
  // int minElem = *min_element(stones.begin(), stones.end());
  // vector<vector<int>> dp(k + 1, vector<int>(3, -1));
  // return solveHelper(stones, minElem, k, false, dp);

  return solveHelperTab(stones, k);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int k;
  cin >> k;
  unordered_set<int> stones;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    stones.insert(t);
  }

  if (solve(stones, k))
    cout << "Second";
  else
    cout << "First";

  return 0;
}