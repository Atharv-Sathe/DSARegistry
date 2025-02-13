#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
Given a rows x cols binary matrix filled with 0's and 
1's, find the largest rectangle containing only 1's and return its area.
*/

int largestRectHisto(vector<int>& heights) {
    stack<int> st;
    int areaMax = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int curH = heights[st.top()];
            st.pop();
            int width = (st.empty()) ? i : i - st.top() - 1;
            areaMax = max(areaMax, curH * width);
        }
        st.push(i);
    }
    return areaMax;
}

int maximalRectangle(vector<vector<char>>& matrix) {

    // Remember the largest rectange in histogram problem

    // Converting char matrix to integer matrix.
    int r = matrix.size();
    int c = matrix[0].size();
    vector<vector<int>> intMatrix(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (matrix[i][j] == '1') intMatrix[i][j] = 1;
        }
    }

    // Overwrite the intMatrix to store heights of histograms
    for (int col = 0; col < intMatrix[0].size(); col++) {
        int currH = 0;
        for (int row = 0; row < intMatrix.size(); row++) {
            currH += intMatrix[row][col];
            if (intMatrix[row][col]) intMatrix[row][col] = currH;
            else currH = 0;
        } 
    }

    // Iterate over each row and apply larg histo 
    int maxArea = 0;
    for (auto& row: intMatrix) {
        maxArea = max(maxArea, largestRectHisto(row));
    }
    return maxArea;
}

int main() {
    
    return 0;
}