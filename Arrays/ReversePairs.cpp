#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/

void countReversePairs(vector<int>& arr, int left, int mid, int right, int& count) {
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while(j <= right && (long long)arr[i] > 2LL * arr[j]) j++;
        count += (j - (mid + 1));
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Creating temporary arrays
    vector<int> l(n1, 0), r(n2, 0);
    
    for (int i = 0; i < n1; i++) l[i] = arr[left + i];
    for (int i = 0; i < n2; i++) r[i] = arr[mid + i + 1];
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) arr[k++] = l[i++];
    while(j < n2) arr[k++] = r[j++];
}

void mergeSort(vector<int>& arr, int left, int right, int& count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);
        countReversePairs(arr, left, mid, right, count);
        merge(arr, left, mid, right);
    } 
}

int reversePairs(vector<int>& nums) {
    // Brute Force n ^ 2
    // int count = 0;
    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size(); j++) {
    //         if (nums[i] > (long long)2 * nums[j]) count++;
    //     }
    // }
    // return count;

    // Optimized n log n
    int count = 0;
    mergeSort(nums, 0, nums.size() - 1, count);
    return count;
}

int main() {
  
  return 0;
}