#include<iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int total = 1 << n;
  for (int i = 0; i < total; i++) {
    int gray = i ^ (i >> 1);
    string bits;
    for (int j = n - 1; j >= 0; j--) {
      bits.push_back((gray >> j) & 1 ? '1' : '0');
    }
    cout << bits << "\n";
  }
  return 0;
}

