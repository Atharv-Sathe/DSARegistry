#include <bits/stdc++.h>
using namespace std;

/*
There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.

Link : https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/
Read Editorial
*/

class Solution {
 private:
  // Less Clever
  int solveTab(vector<vector<int>>& fruits) {
    int n = fruits.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    vector<vector<int>> curr(n, vector<int>(n, -1));

    // dp[k][j2][i3] This represents number of fruits collected after
    // k moves have been made and child 2 is at (k, j2) and child 3 is
    // at (i3, k)
    dp[n - 1][n - 1] = fruits[0][n - 1] + fruits[n - 1][0];
    int fruitsC1 = fruits[0][0];
    for (int k = 1; k < n; k++) {
      fruitsC1 += fruits[k][k];
      int start = max(0, n - 1 - k);
      for (int j2 = start; j2 < n; j2++) {
        for (int i3 = start; i3 < n; i3++) {
          int maxPrevScore = -1;

          for (int prevJ2 = -1; prevJ2 <= 1; prevJ2++) {
            for (int prevI3 = -1; prevI3 <= 1; prevI3++) {
              int prevC2 = j2 + prevJ2;
              int prevC3 = i3 + prevI3;

              if (prevC2 >= 0 && prevC2 < n && prevC3 >= 0 && prevC3 < n) {
                maxPrevScore = max(maxPrevScore, dp[prevC2][prevC3]);
              }
            }
          }

          if (maxPrevScore == -1)
            continue;  // it is impossible to reach this step

          int currentFruits;
          if (k == j2 && k == i3)
            currentFruits = 0;  // All three meet
          else if (k == j2)
            currentFruits = fruits[i3][k];  // C1 and C2 meet
          else if (k == i3)
            currentFruits = fruits[k][j2];  // C1 and C3 meet
          else
            currentFruits = fruits[k][j2] + fruits[i3][k];
          curr[j2][i3] = maxPrevScore + currentFruits;
        }
      }
      dp.swap(curr);
    }
    return dp[n - 1][n - 1] + fruitsC1;
  }

 public:
  // clever pro max
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int n = fruits.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += fruits[i][i];
    }

    auto dp = [&]() -> int {
      vector<int> prev(n, INT_MIN), curr(n, INT_MIN);
      prev[n - 1] = fruits[0][n - 1];
      for (int i = 1; i < n - 1; i++) {
        for (int j = max(n - 1 - i, i + 1); j < n; j++) {
          // We could have reached this state form j, j - 1 or j + 1
          int best = prev[j];
          if (j - 1 >= 0) best = max(best, prev[j - 1]);
          if (j + 1 < n) best = max(best, prev[j + 1]);
          curr[j] = best + fruits[i][j];
        }
        swap(prev, curr);
      }
      return prev[n - 1];
    };

    ans += dp();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // Transposing so now upper diag becomes lower diag and vice versa
        swap(fruits[j][i], fruits[i][j]);
      }
    }

    ans += dp();
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}