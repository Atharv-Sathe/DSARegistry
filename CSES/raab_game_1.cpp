#include<iostream>
using namespace std;

bool solve(int n, int a, int b) {
  int ties = n - a - b;
  if (ties < 0) return false;
  n -= ties; // That many times they play the same card
  if (n < 0) return false;
  if (n >= 1 && (a == n || b == n)) return false; // Each will win at least once, because they both have a highest card
  // Logic :
  // if B needs to win n - 1 games (and A wins 1 game) then 
  // B will always play 1 card higher than A and in the last game B plays the available small card
  // Similarly if B needs to win n - 2 games (and A wins 2 games) then
  // B will always play 2 cards higher than A and in the last two games B plays the available small card
  cout << "YES\n";
  // Alice plays
  for (int i = 1; i <= n; i++) {
    cout << i << " ";
  }
  for (int i = n + 1; i <= n + ties; i++) {
    cout << i << " ";
  }
  cout << "\n";
  // Bob Plays
  for (int i = 1; i <= n; i++) {
    int x = i + a;
    if (x > n) {
      x -= n;
    }
    cout << x << " ";
  }
  for (int i = n + 1; i <= n + ties; i++) {
    cout << i << " ";
  }
  cout << "\n";
  return true;
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (!solve(n, a, b)) {
      cout << "NO\n";
    }
  }
  return 0;
}
