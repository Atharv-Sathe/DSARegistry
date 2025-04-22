#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
You are given an integer array nums of 2 * n integers. You need to
partition nums into two arrays of length n to minimize the absolute
difference of the sums of the arrays. To partition nums, put each
element of nums into one of the two arrays.

Return the minimum possible absolute difference.
*/

// Meet in the middle
/*
Detailed:

Divide the original array in two arbitary parts, each of size n. LeftPart: [0, n-1], RightPart[n,2 * n-1]
Find all possible sums in each part.
As each part will be of size <= 15
We can safely enumerate all possible sums in each part.
For each part, store the sum of a subset along with the size of the subset.
In Code:
I have used two 2-D vectors, left and right, to store sums of all possible subset.
Left[ i ]: stores all possible sums of the subset of size i, in the left part.
Similarly, for right part.
Requirement: We need to divide the original array in two parts of size n, each. Such that the absolute difference of sum is minimised.
Let say from left part we take a subset of size sz (Let's say its sum is a), then from right part we need to take a subset of size of n-sz (Let's say its sum is b). Then, Part1Sum = a+b.
We have to minimise abs(Part1Sum - Part2Sum)
Now, Part1Sum = a+b and Part2Sum = TotalSum - (a+b)
Thus we have to minimise, abs(TotalSum -2 a - 2 b)
Now we iterate over a, and binary search b in the vector right
TC
O(2^n * log(2^n))

This technique commonly known as Meet In Middle. Commonly used when 25 <= array_size <= 40

*/

int minimumDifference(vector<int>& nums) {
  // Meet in the Middle
  int n = nums.size();
  int sum = accumulate(begin(nums), end(nums), 0);

  int N = n / 2;
  vector<vector<int>> left(N + 1), right(N + 1);

  for (int mask = 0; mask < (1 << N); mask++) {
      int sz = 0, l = 0, r = 0;
      for (int i = 0; i < N; i++) {
          if (mask & (1 << i)) {
              sz++;
              l += nums[i], r += nums[i + N];
          }
      }
      left[sz].push_back(l);
      right[sz].push_back(r);
  }

  for (int i = 0; i <= N; i++) {
      sort(right[i].begin(), right[i].end());
  }

  int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

  for (int i = 1; i < N; i++) {
      for (int a: left[i]) {
          int ideal = (sum - 2*a) / 2;
          auto& requiredRight = right[N - i];
          auto iter = lower_bound(requiredRight.begin(), requiredRight.end(), ideal);

          if (iter != requiredRight.end()) res = min(res, abs(sum - 2 * (a + *iter)));
          if (iter != requiredRight.begin()) res = min(res, abs(sum - 2 * (a + *(--iter))));
      }
  }
  return res;
}

int main()
{
  vector<int> nums = {3, 9 , 7 , 3};
  cout << minimumDifference(nums) << endl;

  return 0;
}