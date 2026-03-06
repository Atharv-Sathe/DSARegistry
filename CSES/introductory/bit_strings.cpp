#include<iostream>
using namespace std;

int main() {
  int n; 
  cin >> n;
  int ans = 1;
  int MOD = 1e9 + 7;
  for (int i = 0; i < n; i++ ) {
    ans = (ans * 2) % MOD;
  }
  cout << ans;
  return 0;
}
