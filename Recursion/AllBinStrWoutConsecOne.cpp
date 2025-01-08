#include <iostream>
#include <unordered_map>
#include <climits>
#include <bitset>
using namespace std;


void genAllStrWoutConsecOne(int k, char str[], int n, int &count) {
  if (n == k) {
    str[n] = '\0';
    cout << str;
    bitset<64> dec(str);
    cout << " = " << dec.to_ulong() << endl;
    count++;
    return;
  }
  
  // If previous character is 1
  if (str[n - 1] == '1') {
    str[n] = '0';
    genAllStrWoutConsecOne(k, str, n + 1, count);
  }
  
  // if previous character is 0
  if (str[n - 1] == '0') {
    str[n] = '0';
    genAllStrWoutConsecOne(k, str, n + 1, count);
    
    str[n] = '1';
    genAllStrWoutConsecOne(k, str, n + 1, count);
  }
}



void generateAllStrings(int k) {
  if (k <= 0) return;
  char str[k + 1];
  int count = 0;
  str[0] = '0';
  genAllStrWoutConsecOne(k, str, 1, count);
  
  str[0] = '1'; 
  genAllStrWoutConsecOne(k, str, 1, count);
  cout << "Total Strings Generated: " << count << endl;
  
}

int main() 
{
    int k = 10;
    generateAllStrings(k);
    return 0;
}