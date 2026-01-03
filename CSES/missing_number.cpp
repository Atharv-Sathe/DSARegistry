#include<iostream>
using namespace std;

int main() {
  int n; 
  cin >> n;
  unsigned long long expectedSum = ((1ull * n) * (n + 1)) / 2;
  for (int i = 1; i < n; i++) {
       int num;
       cin >> num;
       expectedSum -= num;
  }
  cout << expectedSum;
  return 0;
}
