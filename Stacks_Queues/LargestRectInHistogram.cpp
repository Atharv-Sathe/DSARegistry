#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Given an array of integers heights representing the histogram's bar height 
where the width of each bar is 1, return the area of the largest rectangle 
in the histogram.
*/

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        int currentH = (i == n) ? 0 : heights[i];
        while(!st.empty() && heights[st.top()] > currentH) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    
    return 0;
}