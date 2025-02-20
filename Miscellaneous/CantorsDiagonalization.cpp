#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <math.h>
using namespace std;

/*
Given an array of strings nums containing n unique binary strings each 
of length n, return a binary string of length n that does not appear in
 nums. If there are multiple answers, you may return any of them.
*/

string findDifferentBinaryString(vector<string>& nums) {
  int n = nums.size();
  vector<int> freq(pow(2, n), 0);
  for (const auto& i : nums) {
      bitset<16> temp(i);
      freq[(int)temp.to_ulong()]++;
  }

  string ans = "";
  for (int i = 0; i < pow(2, n); i++) {
    cout << "hello";
      if (!freq[i]) {
          bitset<16> temp(i);
          ans = temp.to_string().substr(16 - n, n);
          break;
      }
  }
  return ans;
}


int main() {
  vector<string> nums = {"00","01"};
  cout << findDifferentBinaryString(nums);

  return 0;
}