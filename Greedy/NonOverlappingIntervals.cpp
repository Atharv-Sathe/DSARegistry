#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest 
of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For 
example, [1, 2] and [2, 3] are non-overlapping.
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());
  int left = intervals[0][0], right = intervals[0][1];
  int count = 0;
  for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i][0] < right) {
          count++;
          // Keep the interval which ending sooner
          if (right > intervals[i][1]) left = intervals[i][0], right = intervals[i][1];
      } else right = intervals[i][1], left = intervals[i][0];
  }
  return count;
}

int main() {
  
  return 0;
}