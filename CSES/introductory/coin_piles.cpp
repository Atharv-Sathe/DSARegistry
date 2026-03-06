#include<iostream>
using namespace std;

void solve(int a, int b) {
  while(a > 0 && b > 0) {
    if (a >= b) {
      a -= 2;
      b--;
    } else {
      a--;
      b -= 2;
    }
  }
  if (a == b) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return;
}

int main() {
  int t; 
  cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    // T: O(N)
    // solve(a, b);
    
    if ((1ull * a + b) % 3 == 0 && (!(a > 2 * b) && !(b > 2 * a))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

    

