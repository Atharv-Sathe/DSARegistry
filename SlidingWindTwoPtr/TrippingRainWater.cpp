#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it can trap after raining.
*/

int trap(vector<int>& height) {
    // Two Pointer Solution O(1) space and O(n) time
    int i = 0, j = height.size() - 1;
    int leftMax = 0, rightMax = 0; 
    int total = 0;
    while(i < j) {
        // If you have a smaller element on the right
        if (height[i] <= height[j]) {
            // This suggests you may store some water
            if (leftMax > height[i]) total += leftMax - height[i];
            else leftMax = height[i];
            i++; 
        } else {
            if (rightMax > height[j]) total += rightMax - height[j];
            else rightMax = height[j];
            j--;
        }
    }
    return total;
}

int main() {
    
    return 0;
}