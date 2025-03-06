#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int n1 = nums1.size(), n2 = nums2.size();

  int countOnLeft = (n1 + n2 + 1) / 2;

  // Choosing x numbers from the shorter array, always make nums1 shorter
  if (n2 < n1) {
      swap(nums1, nums2);
      swap(n1, n2); 
  }
  int low = 0, high = min(countOnLeft, n1), mid1, l1, l2, r1, r2;

  while(low <= high) {
      mid1 = low + (high -  low) / 2;

      int mid2 = countOnLeft - mid1;

      l1 = (!mid1) ? INT_MIN : nums1[mid1 - 1]; 
      l2 = (!mid2) ? INT_MIN : nums2[mid2 - 1]; 
      r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
      r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

      // Checking if this config is valid or not
      if (l1 > r2) high = mid1 - 1; // Reducing the number of elements we can choose from nums1
      else if (l2 > r1) low = mid1 + 1; // Increasing the number of element we can choose from nums2
      else break;
  }
  double median;
  if ((n1 + n2) & 1) median = max(l1, l2);
  else median = (double)(max(l1, l2) + min(r1, r2)) / 2;
  return median; 
}

int main() {
  
  return 0;
}