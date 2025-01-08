#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isValid(vector<string>& board, int row, int col, int n) {
    // Checking all entire column above for queens
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
        return false;
        }
    }

    // Checking for upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // Checking for upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
} 


void backtrack(int n, int row, vector<string>& board, vector<vector<string>>& result) {
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isValid(board, row, i, n)) {
        board[row][i] = 'Q';
        backtrack(n, row + 1, board, result);
        board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    backtrack(n, 0, board, result);
    return result;
}


int main() {
	int n;
	cin >> n;
  vector<vector<string>> result = solveNQueens(n);
	return 0;
}
