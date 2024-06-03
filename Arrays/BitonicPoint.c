/*
Given an array arr of n elements that is first strictly increasing and then maybe strictly 
decreasing, find the maximum element in the array.
Note: If the array is increasing then just print the last element will be the maximum value.
*/

// An important thing to note here is that all elements will be distinct as the array is strictly
// increasing and strictly decreasing.
// Using Binary Search to solve the question in (log n) time complexity.
#include <stdio.h>

int findMax(int arr[], int low, int high) {
    // If array has one element then that will be the maximum
    if (low == high) 
        return arr[low];

    // If array has only two elements
    if (high == low + 1) {
        if (arr[high] > arr[low])
            return arr[high];
        else 
            return arr[low];
    }

    int mid = (low + high) / 2;

    // If mid element is greater than both the neighbours then that is the max as all elemets after
    // will strictly decrease.
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        return arr[mid];
    
    // if mid element is greater than the previous element and smaller then next element then max 
    // element is in the second half
    if (arr[mid] < arr[mid + 1] && arr[mid] > arr[mid - 1])
        return findMax(arr, mid + 1, high);
    
    // if mid element is samller then the previous element and greater than the next element then max
    // element is in the first half
    if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        return findMax(arr, 0, mid - 1);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = findMax(arr, 0, size - 1);

    printf("Maximum element: %d\n", result);

    return 0;
}