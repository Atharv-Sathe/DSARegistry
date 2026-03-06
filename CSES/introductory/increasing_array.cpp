#include<iostream>
using namespace std;

int main() {
  int n; 
  cin >> n;
  unsigned long long moveCount = 0; 
  int prevElem;
  cin >> prevElem;
  for (int i = 1; i < n; i++) {
       int curElem;
       cin >> curElem;
       if (curElem < prevElem) {
       moveCount += prevElem - curElem;
       }
       else {
       prevElem = curElem;
       }
  }
  cout << moveCount;
  return 0;
}
        
