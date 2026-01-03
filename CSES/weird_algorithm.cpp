#include<iostream>
using namespace std;

void solve(unsigned long long n) {
  cout << n << " ";
  while(n != 1) {
    if (n & 1) {
      n  = n * 3 + 1;
      cout << n << " ";
    } else {
      n /= 2;
      cout << n << " ";
    }
  }
}

int main() {
  unsigned long long n;
  cin >> n;
  solve(n);
}
