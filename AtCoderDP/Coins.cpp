#include <bits/stdc++.h>
using namespace std;

/*
https://atcoder.jp/contests/dp/tasks/dp_i
*/

long double getMorehead(vector<long double>& probab, int i, int headCount, vector<vector<long double>>& dp) {
  int n = probab.size();
  if (i == n) {
    return (headCount >= ((n + 1) / 2)) ? 1 : 0;
  }
  if (dp[i][headCount] != -1) return dp[i][headCount];

  // Tails
  long double tails = (1 - probab[i]) * getMorehead(probab, i + 1, headCount, dp);

  // Heads
  long double  heads = probab[i] * getMorehead(probab, i + 1, headCount + 1, dp);
  return dp[i][headCount] = heads + tails; 
}

long double tabulation(vector<long double>& probabilites) {
  int n = probabilites.size();

  // Here dp[j] represents the probability of getting
  // exactly j heads after processing the coins so far
  vector<long double> dp(n + 1, 0.0);
  dp[0] = 1.0; // Probab of getting 0 heads after processing 0 coins

  /*
    NOTE : 
    1. dp[j + 1] += dp[j] * p[i];
    This line handles the heads case. We are adding the probability of "having j heads 
    before, and then tossing a head" to dp[j+1].

    We use += (add to) because dp[j+1] already contains a value from this step: it holds 
    the probability from the "tails" case. In the previous iteration of the loop (when the 
    loop variable was j+1), its value was set. So, this line completes the calculation for 
    the new dp[j+1] by adding the final piece of its probability.

    new_dp[j+1] = (prob from tails case) + (prob from heads case)

    2. dp[j] = dp[j] * (1.0 - p[i]);
    This line handles the tails case. It calculates the probability of "having j heads before, 
    and then tossing a tail".

    We use = (overwrite) because this is the first of the two probabilities that will make up 
    the new dp[j]. We are overwriting the old dp[j] value (which we no longer need for any future 
    calculations in this loop because we're iterating backwards) with the first part of its new 
    value. The other part—the "heads" case from dp[j-1]—will be added to it in the next iteration 
    of the loop.
  */

  for (int i = 0; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      // Head
      dp[j + 1] += dp[j] * probabilites[i];
      // Tail
      dp[j] = dp[j] * (1.0 - probabilites[i]); 
    }
  }

  long double finalProbab = 0.0;
  for (int i = (n + 1) / 2; i <= n; i++) {
    finalProbab += dp[i];
  }
  return finalProbab;
}


int main() {
  // Fast I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<long double> probabilities(n);
  for (int i = 0; i < n; i++) cin >> probabilities[i];

  vector<vector<long double>> dp(n, vector<long double>(n + 1, -1));
  cout << fixed << setprecision(10) << getMorehead(probabilities, 0, 0, dp);

  // cout << fixed << setprecision(10) << tabulation(probabilities);
  return 0;
}