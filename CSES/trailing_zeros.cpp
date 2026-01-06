#include<iostream>
using namespace std;


int main() {
  int n;
  cin >> n;
  int fiveCount = 0;
  int pow = 5;
  while(n >= pow) {
    fiveCount += n / pow;
    pow *= 5;
  }
  cout << fiveCount;
  return 0;
}
