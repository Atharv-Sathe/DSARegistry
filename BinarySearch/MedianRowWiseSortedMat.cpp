#include <iostream>
#include <vector>
using namespace std;

/*
Given a row-wise sorted matrix where the number of 
rows and columns is always odd, find the median of the matrix.
*/

int median(vector<vector<int>> &mat) {
  // Brute Force
  // priority_queue<int> q;
  // int r = mat.size(), c = mat[0].size();
  // for (const auto& r: mat) {
  //     for (const int i: r) {
  //         q.push(i);
  //     }
  // }
  // int n = (r * c) / 2;
  // while(n--) {
  //     q.pop();
  // }
  // return q.top();
  
  
  // Efficient Approach
  int r = mat.size(), c = mat[0].size();
  
  int maxVal = INT_MIN, minVal = INT_MAX;
  
  // Finding the max and min val in mat
  for (int i = 0; i < r; i++) {
      minVal = min(minVal, mat[i][0]);
      maxVal = max(maxVal, mat[i][c-1]);
  }
  
  // The median element will have exactly (r * c + 1) / 2 elements less than
  // or equal to it in the matrix, hence we use binary search on the search space
  // minVal to maxVal, for every value we check if there are exactly (r * c + 1) / 2 
  // elements smaller or equal to it, if less small then we shift search space to 
  // right to increase number of smaller elements, else we move search space to left
  int desired = (r * c + 1) / 2;
  int lo = minVal, hi = maxVal;
  while(lo < hi) {
      int mid = lo  + (hi - lo) / 2;
      
      int count = 0;
      // Count no. of elems smaller or equal to this.
      for (int i = 0; i < r; i++) {
          count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
      }
      
      // Even without explicitly stating this solution
      // verifies the solution found is in mat, since
      // lets say a num satisfies the criteria but isn't 
      // in the mat, in that case there me another num 
      // lesser than it which may also satisfy the criteria 
      // hence we shift search space to left but include curr ans 
      // in the search space.
      if (count < desired) lo = mid + 1;
      else hi = mid;
  }   
  return lo;
}

int main() {
  
  return 0;
}