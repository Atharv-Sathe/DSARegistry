#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it can trap after raining.
*/

int trap(vector<int>& height) {
    // Stack Solution
    stack<int> st;
    int water = 0;
    for (int i = 0; i < height.size(); i++) {
        while(!st.empty() && height[i] > height[st.top()]) {
            int topH = height[st.top()];
            st.pop();
            if (st.empty()) break; // No Left Boundry

            int distance = i - st.top() - 1;
            int boundedH = min(height[i], height[st.top()]) - topH;
            water += distance * boundedH;
        }
        st.push(i);
    }
    return water;
}

int main() {
    
    return 0;
}