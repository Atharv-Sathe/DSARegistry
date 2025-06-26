#include <iostream>
#include <vector>
using namespace std;

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture
regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region
with 'X' cells and none of the region cells are on the edge of the board. To
capture a surrounded region, replace all 'O's with 'X's in-place within the
original board. You do not need to return anything.

*/

vector<pair<int, int>> dirc{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<char>>& board, int i, int j) {
  int m = board.size();
  int n = board[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;

  board[i][j] = '#';  // Temprorily mark as visited

  for (auto [x, y] : dirc) {
    dfs(board, i + x, j + y);
  }
}

void solve(vector<vector<char>>& board) {
  int m = board.size();
  int n = board[0].size();

  // Mark all zeros connected to boundry as '#'
  for (int i = 0; i < n; i++) {
    if (board[0][i] == 'O') dfs(board, 0, i);
    if (board[m - 1][i] == 'O') dfs(board, m - 1, i);
  }

  for (int i = 0; i < m; i++) {
    if (board[i][0] == 'O') dfs(board, i, 0);
    if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 'O')
        board[i][j] = 'X';
      else if (board[i][j] == '#')
        board[i][j] = 'O';
    }
  }
}

int main() { return 0; }