#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  deque<int> q;
  int i = 0, j = i + k - 1;
  vector<int> answer;
  for (int l = 0; l < k; l++) {
      while(!q.empty() && nums[q.back()] <= nums[l]) q.pop_back();
      q.push_back(l);
  }
  answer.push_back(nums[q.front()]);
  i++; j++;
  while(j < nums.size()) {
      // Remove all elements from queue which are not in curr Win
      while(!q.empty() && q.front() < i) q.pop_front();

      while(!q.empty() && nums[q.back()] <= nums[j]) q.pop_back();
      q.push_back(j);
      answer.push_back(nums[q.front()]);
      i++; j++;
  }
  return answer;
}

int main() {
  vector<int> nums = {1,3,1,2,0,5};
  int k = 3;
  maxSlidingWindow(nums, k);
  cout << "hello\n";
  return 0;
}