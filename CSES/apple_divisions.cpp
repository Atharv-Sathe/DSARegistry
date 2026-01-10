#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void solve(vector<int>& apples) {
  sort(apples.begin(), apples.end());
  long long wt_a = 0, wt_b = 0;
  int n = apples.size();
  for (int i = n - 1; i >= 0; i--) {
    if (wt_a <= wt_b) {
      wt_a += apples[i];
    } else {
      wt_b += apples[i];
    }
  }
  cout << abs(wt_a - wt_b);
  return;
}

void recurse(vector<int>& apples, int i, long long sum, long long total, long long& minDiff) {
  if (i == apples.size()) {
    long long diff = abs(total - 2 * sum);
    minDiff = min(diff, minDiff);
    return;
  }
  recurse(apples, i + 1, sum + apples[i], total, minDiff);
  recurse(apples, i + 1, sum, total, minDiff);
}

int main() {
  int n;
  cin >> n;
  vector<int> apples;
  long long sum = 0;
  while(n--) {
    int wt;
    cin >> wt;
    sum += wt;
    apples.push_back(wt);
  }
  // solve(apples);
  long long minDiff = LLONG_MAX;
  recurse(apples, 0, 0, sum, minDiff);
  cout << minDiff;
  return 0;
}
