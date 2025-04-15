#include <iostream>
#include <vector>
using namespace std;

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path 
through matrix.

A falling path starts at any element in the first row and chooses the element in 
the next row that is either directly below or diagonally left/right. Specifically, 
the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), 
or (row + 1, col + 1).
*/


int recurseNaive(vector<vector<int>>& matrix, int r, int c) {
  int m = matrix.size();
  if (r == m - 1) return matrix[r][c];

  int leftMove = (c >= 1) ? recurseNaive(matrix, r + 1, c - 1) : INT_MAX;
  int midMove = recurseNaive(matrix, r + 1, c);
  int rightMove = (c <= m - 2) ? recurseNaive(matrix, r + 1, c + 1) : INT_MAX;  

  return matrix[r][c] + min(leftMove, min(midMove, rightMove));      
}

int memoization(vector<vector<int>>& matrix, vector<vector<int>>& memo, int r, int c) {
  int m = matrix.size();
  if (r == m - 1) return matrix[r][c];
  if (memo[r][c] != -1) return memo[r][c];

  int leftMove = (c >= 1) ? memoization(matrix, memo, r + 1, c - 1) : INT_MAX;
  int midMove = memoization(matrix, memo, r + 1, c);
  int rightMove = (c <= m - 2) ? memoization(matrix, memo, r + 1, c + 1) : INT_MAX;  

  memo[r][c] = matrix[r][c] + min(leftMove, min(midMove, rightMove)); 
  return memo[r][c];
}

int tabulation(vector<vector<int>>& matrix) {
  int m = matrix.size();
  vector<vector<int>> tab(m, vector<int>(m, INT_MAX));
  for (int i = 0; i < m; i++) {
      tab[m - 1][i] = matrix[m - 1][i];
  }

  for (int j = m - 2; j >= 0; j--) {
      for (int k = 0; k < m; k++) {
          if (!(k >= 0 && k < m)) continue;
          int leftMove = (k >= 1) ? tab[j + 1][k - 1] : INT_MAX;
          int midMove = tab[j + 1][k];
          int rightMove = (k <= m - 2) ? tab[j + 1][k + 1] : INT_MAX;
          tab[j][k] = matrix[j][k] + min(midMove, min(leftMove, rightMove));
      }
  }

  return *min_element(tab[0].begin(), tab[0].end());
}


int tabulationSpaceOp(vector<vector<int>>& matrix) {
  int m = matrix.size();
  vector<int> tab = matrix[m - 1];

  for (int j = m - 2; j >= 0; j--) {
      int tempLeft = tab[0];
      for (int k = 0; k < m; k++) {
          if (!(k >= 0 && k < m)) continue;
          int leftMove = (k >= 1) ? tempLeft : INT_MAX;
          int midMove = tab[k];
          int rightMove = (k <= m - 2) ? tab[k + 1] : INT_MAX;
          tempLeft = tab[k];
          tab[k] = matrix[j][k] + min(midMove, min(leftMove, rightMove));
      }
  }

  return *min_element(tab.begin(), tab.end());
}

int minFallingPathSum(vector<vector<int>>& matrix) {
  // int minFallingPSum = INT_MAX;
  // int m = matrix.size();
  // vector<vector<int>> memo(m , vector<int>(m, -1));
  // for (int i = 0; i < m; i++) {
  //     minFallingPSum = min(minFallingPSum, memoization(matrix, memo, 0, i));
  // }
  // return minFallingPSum;

  // return tabulation(matrix);
  return tabulationSpaceOp(matrix);
}

int main() {
  
  return 0;
}