#include<iostream>
#include<cmath>
using namespace std;


unsigned long long firstColNum(unsigned long long c) {
  unsigned long long temp = (c - 1) / 2;
  return 1 + (c/2) + (4 * temp * temp + 3 * temp);
}

unsigned long long firstRowNum(unsigned long long r) {
  unsigned long long temp = r / 2;
  return 1 + ((r - 1) / 2) + (4 * temp * temp - temp);
}

unsigned long long solve(unsigned long long x, unsigned long long y) {
  if (y <= x) {
    long long sign = (x & 1) ? 1 : -1;
    return firstRowNum(x) + sign * (y - 1);
  }
  long long sign = (y & 1) ? -1 : 1;
  return firstColNum(y) + sign * (x - 1);
}

int main() {
  int t; 
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << solve(x, y) << "\n";
  }
  return 0;
}
