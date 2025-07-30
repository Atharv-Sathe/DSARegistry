#include <bits/stdc++.h>
#define fr(i, s, e, inc)  for (int i = s; i < e; i+=inc)
using namespace std;

const int maxDishes = 301;
int N;
double dp[maxDishes][maxDishes][maxDishes];
bool visited[maxDishes][maxDishes][maxDishes];

/*
  Recurrence Relation
  E(d1, d2, d3) = 1 + p1 * E(d1 - 1, d2, d3) 
                  + p2 * E(d1 + 1, d2 - 1, d3) 
                  + p3 * E(d1, d2 + 1, d3 - 1)
                  + p0 * E(d1, d2, d3);

  let E(d1, d2, d3) = x;
  x(1 - p0) = 1 + p1 * E(d1 - 1, d2, d3) 
              + p2 * E(d1 + 1, d2 - 1, d3) 
              + p3 * E(d1, d2 + 1, d3 - 1)
  
  x = (1 + p1 * E(d1 - 1, d2, d3) 
      + p2 * E(d1 + 1, d2 - 1, d3) 
      + p3 * E(d1, d2 + 1, d3 - 1)) / (1 - p0);

*/

double solve(int d1, int d2, int d3) {
  if (d1 == 0 && d2 == 0 && d3 == 0) return 0.0;
  if (visited[d1][d2][d3]) return dp[d1][d2][d3];
  
  double ans = 1.0; // Since every call is a dice role
  
  // In one call you may land on a dish with any number of sushies
  if (d1 > 0) {
    ans += (1.0 *  d1 / N) * solve(d1 - 1, d2, d3);
  }
  
  if (d2 > 0) {
    ans += (1.0 * d2 / N) * solve(d1 + 1, d2 - 1, d3);
  }
  
  if (d3 > 0) {
    ans += (1.0 * d3 / N) * solve(d1, d2 + 1, d3 - 1);
  }

  // The probability landing on a 0 place
  double p0 = (double)(N - d1 - d2 - d3) / N;
  
  ans /= (1 - p0);
  visited[d1][d2][d3] = true; 
  return dp[d1][d2][d3] = ans;
}

// Tabulation (bottom-up DP) approach to solve the expected moves problem.
// dp[n1][n2][n3] represents the expected number of moves needed to finish all sushi,
// starting with n1 dishes with 1 sushi, n2 dishes with 2 sushi, and n3 dishes with 3 sushi.
double solveTab(vector<int>& cnt) {
  // Base case: If there are no sushi left on any plate, expected moves = 0.
  dp[0][0][0] = 0.0;

  // s = total number of plates with sushi (n1 + n2 + n3)
  for (int s = 1; s <= N; s++) {
    // n3 = number of plates with 3 sushi
    for (int n3 = 0; n3 <= s; n3++) {
      // n2 = number of plates with 2 sushi
      for (int n2 = 0; n2 <= s - n3; n2++) {
        int n1 = s - n3 - n2; // n1 = number of plates with 1 sushi

        // Probability of picking an empty plate (no sushi)
        double term0 = (double)(N - s) / N;

        // Expected moves if we pick a plate with 1, 2, or 3 sushi
        double term1 = 0.0, term2 = 0.0, term3 = 0.0;
        if (n1 > 0) term1 = (1.0 * n1 / N) * dp[n1 - 1][n2][n3];
        if (n2 > 0) term2 = (1.0 * n2 / N) * dp[n1 + 1][n2 - 1][n3];
        if (n3 > 0) term3 = (1.0 * n3 / N) * dp[n1][n2 + 1][n3 - 1];

        // The recurrence: expected moves = 1 (for this move) + expected moves for each possible outcome,
        // divided by the probability of not picking an empty plate (1 - term0).
        dp[n1][n2][n3] = (1 + term1 + term2 + term3) / (1 - term0);
      }
    }
  }

  // Return the expected moves for the initial configuration.
  return dp[cnt[1]][cnt[2]][cnt[3]];
}

int main() {
  cin >> N;
  vector<int> cnt(4);
  fr (i, 0, N, 1) {
    int x; cin >> x;
    cnt[x]++;
  }

  // cout << fixed << setprecision(10) << solve(cnt[1], cnt[2], cnt[3]);
  cout << fixed << setprecision(10) << solveTab(cnt);
  return 0;
}