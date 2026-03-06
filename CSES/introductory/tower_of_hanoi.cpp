#include<iostream>
using namespace std;

void solve(int n, int from, int to) {
  if (!n) {
    return;
  }
  int helper = 6 - from - to;
  solve(n - 1, from, helper);
  cout << from << " " << to << "\n";
  solve(n - 1, helper, to);
}

int main() {
  int n;
  cin >> n;
  cout << ((1 << n) - 1) << "\n";
  solve(n, 1, 3);
  return 0;
}
