#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;

bool isSafe(unordered_set<string>& queens, int i, int j) {
  for (auto& loc : queens) {
    int x = loc[0] - '0';
    int y = loc[1] - '0';
    // Eq 1. i = x
    if (i == x) return false;
    // Eq 2. j = y
    if (j == y) return false;
    // Eq 3. j = -i + (y + x)
    if (j == (-i + y + x)) return false;
    // Eq 4. j = i + (y - x)
    if (j == (i + y - x)) return false;
  }
  return true;
}

int solve(vector<vector<char>>& board, int i, unordered_set<string>& queens) {
  if (i == 8) {
    return 1;
  }
  int ways = 0;
  for (int c = 0; c < 8; c++) {
    if (board[i][c] == '*' || !isSafe(queens, i, c)) {
      continue;
    }
    string posStr = (i == 0) ? "0" : to_string(i);
    posStr += to_string(c);
    queens.insert(posStr); 
    ways += solve(board, i + 1, queens);
    queens.erase(posStr);
  }
  return ways;
}

int main() {
  vector<vector<char>> board(8, vector<char>(8, '.'));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
     char chr;
     cin >> chr;
     if (chr == '*') {
       board[i][j] = chr;
     }
    }
  }
  unordered_set<string> queens;
  cout << solve(board, 0, queens);
  return 0;
}
