#include<iostream>
using namespace std;

// Valid Ways = All Possible Ways - Bad Ways
// The below function comes after solving for the above equation.

void solve(int k) {
  long long ways = 1ll * (k - 1) * (1ll * k * k * k + 1ll * k * k - 8 * k + 16 ) / 2;
  cout << ways << "\n";
  return;
}


int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  return 0;
}
